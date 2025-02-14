#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	//初期化
	posX_ = 0.0f;
	posY_ = 0.0f;
	speed_ = 5.0f;
	radius_ = 10.0f;
	isShot_ = false;
}

void Bullet::Update()
{
	//フラグがオンになったら弾を発射
	if (isShot_)
	{
		posY_ -= speed_;

		//画面外に出たらフラグをオフにする
		if (posY_ <= radius_)
		{
			isShot_ = false;
		}
	}
}

void Bullet::Draw()
{
	//フラグがオンなら描画する
	if (isShot_)
	{
		Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);
	}
}