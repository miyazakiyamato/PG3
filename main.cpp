#include <stdio.h>
#include "Enemy.h"

int main(){

	Enemy* enemy = new Enemy();

	enemy->Update();
	enemy->Update();
	enemy->Update();

	delete enemy;
	return 0;
}