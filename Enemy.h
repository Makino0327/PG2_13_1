#pragma once

class Enemy
{
public:
	//�錾
	float posX_;
	float posY_;
	float speed_;
	float radius_;
	static int isEnemyAlive;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Enemy(float posX, float posY);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Enemy();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

