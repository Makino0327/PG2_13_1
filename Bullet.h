#pragma once
class Bullet
{
public:
	//宣言
	float posX_;
	float posY_;
	float speed_;
	float radius_;
	int isShot_;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

