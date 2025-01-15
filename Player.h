#pragma once
#include "Bullet.h"
class Player
{
public:
	//初期化
	float posX_;
	float posY_;
	float radius_;
	float speed_;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

public:
	//弾の初期化
	Bullet* bullet_[10];
};

