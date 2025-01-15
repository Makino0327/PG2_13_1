#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include <math.h>

const char kWindowTitle[] = "LC1C_24_マキノハルト_タイトル";

int Enemy::isEnemyAlive=true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//プレイヤー
	Player* player = new Player();
	//敵
	Enemy* enemy1 = new Enemy(100.0f,100.0f);
	Enemy* enemy2 = new Enemy(160.0f, 160.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//Rで敵を復活
		if (keys[DIK_R])
		{
			Enemy::isEnemyAlive = true;
		}

		//プレイヤーの更新処理
		player->Update(keys, preKeys);

		//敵の更新処理
		if (Enemy::isEnemyAlive )
		{
			enemy1->Update();
			enemy2->Update();
		}

		//敵と弾の当たり判定
		for (int i = 0; i < 10; i++)
		{
			if (player->bullet_[i]->isShot_)
			{
				if (player->bullet_[i]->radius_ + enemy1->radius_ >=
					sqrtf(powf(player->bullet_[i]->posX_ - enemy1->posX_, 2) +
						powf(player->bullet_[i]->posY_ - enemy1->posY_, 2))
					|| player->bullet_[i]->radius_ + enemy2->radius_ >=
					sqrtf(powf(player->bullet_[i]->posX_ - enemy2->posX_, 2) +
						powf(player->bullet_[i]->posY_ - enemy2->posY_, 2)))
				{
					Enemy::isEnemyAlive = false;
					player->bullet_[i]->isShot_ = false;
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
	
		//描画処理
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

	delete player;
	delete enemy1;
	delete enemy2;

	return 0;
}
