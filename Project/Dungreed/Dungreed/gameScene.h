#pragma once
#include "gameNode.h"
#include "player.h"

class gameScene : public gameNode
{
private:
	image* map;						// ��� �̹���
	player* _player;				// �÷��̾� �̹���
	
	
	RECT _rc;						// �׽�Ʈ�� RECT
	int _x, _y;						// �÷��̾� x, y ��ǥ
	int _cameraX, _cameraY;			// ī�޶� x, y ��ǥ
	bool _cameraHorizontalMoveOk;	// ī�޶��� �¿��̵� ���� ����
	bool _cameraVerticalMoveOk;		// ī�޶��� �����̵� ���� ����

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void playerMove();
};

