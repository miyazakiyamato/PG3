#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
std::vector<std::vector<int>> mapData;  // 2Dマップデータ

void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!\n";
        return;
    }

    std::vector<std::vector<int>> tempData;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        std::string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }
        tempData.push_back(row);
    }

    std::lock_guard<std::mutex> lock(mtx);
    mapData = tempData;
    dataReady = true;
    cv.notify_one();  // 描画スレッドに通知
}

void displayMap() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []() { return dataReady; });  // データが準備されるまで待機

    for (const auto& row : mapData) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::thread loader(loadCSV, "map.csv");
    std::thread renderer(displayMap);

    loader.join();
    renderer.join();

    return 0;
}
