#include "Player.h"
#include <Novice.h>

Player::Player()
{
	//初期化
	posX_ = 500.0f;
	posY_ = 500.0f;
	radius_ = 30.0f;
	speed_ = 5.0f;

	for (int i = 0; i < 10; i++)
	{
		bullet_[i] = new Bullet();
	}
}

Player::~Player()
{
	//弾をdelete
	for (int i = 0; i < 10; i++)
	{
		delete bullet_[i];
	}
}

void Player::Update(char* keys, char* preKeys)
{
	//nullチェック
	if (keys != nullptr || preKeys != nullptr)
	{
		//移動処理
		if (keys[DIK_W])
		{
			posY_ -= speed_;
		}

		if (keys[DIK_A])
		{
			posX_ -= speed_;
		}

		if (keys[DIK_S])
		{
			posY_ += speed_;
		}

		if (keys[DIK_D])
		{
			posX_ += speed_;
		}

		for (int i = 0; i < 10; i++)
		{
			if (!bullet_[i]->isShot_)
			{
				//SPACEで弾を発射
				if (!preKeys[DIK_SPACE] && keys[DIK_SPACE])
				{
					bullet_[i]->isShot_ = true;
					bullet_[i]->posX_ = posX_;
					bullet_[i]->posY_ = posY_;
					break;
				}
			}

			//弾の更新処理
			bullet_[i]->Update();
		}
	}
}

void Player::Draw()
{
	//プレイヤーの描画
	Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, WHITE, kFillModeSolid);

	for (int i = 0; i < 10; i++)
	{
		//弾の描画
		bullet_[i]->Draw();
	}
}