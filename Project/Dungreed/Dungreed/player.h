#pragma once
#include "character.h"

class player : public character, public gameScene
{
private:
	image* _player;					// �÷��̾� �̹���

	RECT _rc;						// �׽�Ʈ�� RECT
	int _x, _y;						// �÷��̾� x, y ��ǥ
	int _cameraX, _cameraY;			// ī�޶� x, y ��ǥ

	int _probeY;					// �ȼ��浹�� ����� Ž�� Y ��ǥ

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	bool pixelCollision(int probeY);
};

