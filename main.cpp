#include <stdio.h>
#include <functional>

#include <random>
#include <Windows.h>
//macとかのUnix系OSの場合
//#include <unistd.h>

//コールバック関数
void DiceResult(int number) {
	int randNum = 0;

	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	// 1.0以上7.0未満の値を等確率で発生させる
	std::uniform_real_distribution<> dist(1.0, 7.0);

	randNum = static_cast<int>(dist(engine));
	printf("%d\n", randNum);
	printf("\nあなたが選んだのは");
	if (number % 2 == 1) {
		printf("奇数");
	}
	else {
		printf("偶数");
	}
	printf("なので\n");
	if (randNum % 2 == number % 2) {
		printf("正解!");
	}
	else {
		printf("不正解!");
	}
}

void setTimeout(std::function<void(int)> fx, int second, int number) {
	//コールバック関数
	Sleep(second * 1000);
	//macとかのUnix系OSの場合
	//sleep(second);
	fx(number);
}

int main(void) {

	int number = 0;

	std::function<void(int)> fx = [](int number) {DiceResult(number); };

	while (true)
	{
		printf("サイコロを振ります。奇数か偶数か当ててみてください。\n1:奇数 2:偶数\n");
		scanf_s("%d", &number);

		printf("コロコロコロ...\n");
		setTimeout(fx, 3, number);

		printf("\n\nもう一度やりますか？\n1:はい 2:いいえ\n");
		scanf_s("%d", &number);
		if (number == 2) {
			break;
		}
	}
	return 0;
}

//[](){}()
//[] ラムダキャプチャ
//() パラメータ定義節 
//{} 複合ステートメント
//() 関数呼び出し式

//キャプチャ記法
//[&] [=] [&x] [x] [&,x] [=,&x] [this] [this,x] 