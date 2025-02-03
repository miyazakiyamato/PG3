#include <stdio.h>
#include <string>
#include <chrono>

int main() {
    // 100000文字のstd::stringを初期化
    std::string a(100000, 'a');

    // コピーの時間計測
    std::chrono::steady_clock::time_point start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;  // コピー
    std::chrono::steady_clock::time_point end_copy = std::chrono::high_resolution_clock::now();

    // ムーブの時間計測
    std::chrono::steady_clock::time_point start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);  // ムーブ
    std::chrono::steady_clock::time_point end_move = std::chrono::high_resolution_clock::now();

    // 時間計算と表示（マイクロ秒）
    int copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    int move_time = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    printf("100,000文字を移動とコピーで比較しました。\n");
    printf("コピー : %dμs\n", copy_time);
    printf("移動 : %dμs\n", move_time);

    return 0;
}