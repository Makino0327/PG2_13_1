#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(float posX, float posY)
{
	//������
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
	//���������Z
	posX_ += speed_;

	//��ʒ[�ɍs�����甽��
	if (posX_ >= 1280.0f-radius_||posX_<=0.0f+radius_)
	{
		speed_ *= -1;
	}
}

void Enemy::Draw()
{
	//�G�̕`��
	if (isEnemyAlive)
	{
		Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>( posY_), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);
	}
}