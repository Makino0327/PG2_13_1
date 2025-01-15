#pragma once
#include "Bullet.h"
class Player
{
public:
	//������
	float posX_;
	float posY_;
	float radius_;
	float speed_;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="keys">�L�[</param>
	/// <param name="preKeys">�O�̃L�[</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

public:
	//�e�̏�����
	Bullet* bullet_[10];
};

