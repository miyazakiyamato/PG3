#pragma once
class Enemy{
public:
	enum class MoveState
	{
		kApproach,
		kShooting,
		kWithdrawal,
	};
public:
	void Update();

	void Approach();
	void Shooting();
	void Withdrawal();
private:
	static void (Enemy::* spFuncTable[])();

	MoveState moveState = MoveState::kApproach;
};

