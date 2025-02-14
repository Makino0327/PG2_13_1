#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(float posX, float posY)
{
	//初期化
	posX_ = posX;
	posY_ = posY;
	speed_ = 3.0f;
	radius_ = 30.0f;
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	//速さを加算
	posX_ += speed_;

	//画面端に行ったら反射
	if (posX_ >= 1280.0f-radius_||posX_<=0.0f+radius_)
	{
		speed_ *= -1;
	}
}

void Enemy::Draw()
{
	//敵の描画
	if (isEnemyAlive)
	{
		Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>( posY_), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);
	}
}