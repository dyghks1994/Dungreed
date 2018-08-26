#pragma once
#include "character.h"

class player : public character
{
	enum CHAR_STATE
	{
		UP,			// ĳ���Ͱ� �����ϸ鼭 ���� �ö󰡰� �ִ� ����
		LANDING,	// ĳ���Ͱ� ���� �������� ����
		DOWN,		// ĳ���Ͱ� �����߿� �Ʒ��� �ϰ��ϰ� �ִ� ����
		DOWNJUMP,	// ĳ���Ͱ� �ϴ� ������ ����ϸ鼭 ��(�ʷ�)�� �����ִ� ����
	};

private:
	CHAR_STATE _state;				// ���� ĳ������ ���¸� ����

	image* _player;					// �÷��̾� �̹���

	RECT _rc;						// �׽�Ʈ�� RECT
	float _x, _y;					// �÷��̾� x, y ��ǥ
	float _jumpCount;				// ���� Ƚ��

	float _angle;					// ���콺 ���⿡ ���� ���� -> �뽬�� ���ݿ� ���
	POINT _anglePoint;				// ���� ĳ������ ��ġ�� ���콺�� ��ġ�� ����ڰ� ���� ����� �Ͱ� �ٸ��� ������ ���ϸ� ������ ����
									// �׷��� ������â �ȿ����� �����̴�(���� �÷��̾�� ������â�� ����� ������), �뽬�� ���Ÿ����ݿ� ����� ������ ���� 
									// POINT(��)�� �ϳ� ����
	RECT _angleRc;					// ���� RECT�� Ȯ���ϱ� ���� �׽�Ʈ�� ��Ʈ
	
	bool  _dash;					// �뽬 �������� �Ǻ��ϴ� ����
	float _dashPower;				// �뽬 �Ŀ�
	float _dashCount;				// �뽬�ϴ� �ð� ī��Ʈ


	float _cameraX, _cameraY;		// ī�޶� x, y ��ǥ

	float _probeI;					// �ȼ��浹 �ݺ��� ����� I ���� -> Ž�� ���� ����
	float _probeY;					// �ȼ��浹�� ����� Ž�� Y ��ǥ -> Ž�� �� ����

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();		// �����¿� �̵� �� ����
	void dash();		// ���콺 ��Ŭ���� �뽬 ���
	bool pixelCollision(int probeY, int probeR, int probeG, int probeB);

	void anglePointMove();
	void cameraMove();
};

