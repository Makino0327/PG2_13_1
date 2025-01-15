#pragma once

class Enemy
{
public:
	//宣言
	float posX_;
	float posY_;
	float speed_;
	float radius_;
	static int isEnemyAlive;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Enemy(float posX, float posY);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

