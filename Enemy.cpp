#include "Enemy.h"
#include <stdio.h>

void Enemy::Update(){
	(this->*spFuncTable[static_cast<size_t>(moveState)])();
}

void Enemy::Approach(){
	printf("“G‚ªÚ‹ßI\n");
	moveState = MoveState::kShooting;
}

void Enemy::Shooting(){
	printf("“G‚ªUŒ‚I\n");
	moveState = MoveState::kWithdrawal;
}

void Enemy::Withdrawal(){
	printf("“G‚ª—£’E!\n");
}

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,
	&Enemy::Shooting,
	&Enemy::Withdrawal,
};
