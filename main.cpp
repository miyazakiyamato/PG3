#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current = 1;

void ThreadNum(int num) {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [&]() { return current == num; }); // num が現在のターンであることを確認
	printf("thread%d\n", num);
	current++; // 次のターンに進む
	cv.notify_all(); // 他のスレッドに通知
}

int main(){
	//マルチスレッド
	std::thread th1(ThreadNum, 1);
	std::thread th2(ThreadNum, 2);
	std::thread th3(ThreadNum,3);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}
