#include "stdafx.h"
#include "gameScene.h"


gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init()
{
	IMAGEMANAGER->addImage("��", "image/gameScene/testMap.bmp", BACKDCSIZEX, BACKDCSIZEY, false, NULL);
	map = IMAGEMANAGER->findImage("��");

	map->setX(0);
	map->setY(0);

	_x = 700;
	_y = 250;
	_rc = RectMakeCenter(_x, _y, 50, 50);

	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;
	_cameraHorizontalMoveOk = false;
	_cameraVerticalMoveOk = false;

	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{
	playerMove();
}

void gameScene::render()
{
	// ���� ���(��)�̹����� ĳ���� �̹����� �׷��� �̹���(���) -> source
	map->render(getMemDC(), map->getX(), map->getY());
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	// ī�޶� �̿��� �����ֱ� ����
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);
	
	
}

void gameScene::playerMove()
{
	// ************************************* ĳ���� ���� **********************************************
	
	// �·� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3;	// �÷��̾� x��ǥ ����
		if (_cameraHorizontalMoveOk) _cameraX -= 3;	// ī�޶� �����̵��� ������ ���¶�� ī�޶� x��ǥ ����
	}

	// ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3;	// �÷��̾� x��ǥ ����
		if (_cameraHorizontalMoveOk) _cameraX += 3; // ī�޶� �����̵��� ������ ���¶�� ī�޶� x��ǥ ����
	}

	// ���� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3;	// �÷��̾� y��ǥ ����
		if (_cameraVerticalMoveOk) _cameraY -= 3; // ī�޶� �����̵��� ������ ���¶�� ī�޶� y��ǥ ����
	}

	// �Ʒ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3;	// �÷��̾� Y��ǥ ����
		if (_cameraVerticalMoveOk) _cameraY += 3; // ī�޶� �����̵��� ������ ���¶�� ī�޶� y��ǥ ����
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= BACKDCSIZEX) _x = BACKDCSIZEX - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= BACKDCSIZEY) _y = BACKDCSIZEY - 25;

	_rc = RectMakeCenter(_x, _y, 50, 50);

	// end of ĳ���� ���� *********************************************************************************


	// ī�޶� ���� ****************************************************************************************
	// ī�޶� �¿� �̵� �������� �Ǻ�
	if (_x <= 0 + WINSIZEX / 2 || _x >= BACKDCSIZEX - WINSIZEX / 2) _cameraHorizontalMoveOk = false;
	else _cameraHorizontalMoveOk = true;

	// ī�޶� ���� �̵� �������� �Ǻ�
	if (_y <= 0 + WINSIZEY / 2 || _y >= BACKDCSIZEY - WINSIZEY / 2) _cameraVerticalMoveOk = false;
	else _cameraVerticalMoveOk = true;

	// ī�޶� ���� ����� �ʵ��� ��ġ ����
	// ī�޶� ���� ���� ���� ��
	if (_cameraX <= 0) _cameraX = 0;
	// ī�޶� ������ ���� ���� ��
	if (_cameraX + WINSIZEX >= BACKDCSIZEX) _cameraX = BACKDCSIZEX - WINSIZEX;
	// ī�޶� ���� ���� ���� ��
	if (_cameraY <= 0) _cameraY = 0;
	// ī�޶� �Ʒ��� ���� ���� ��
	if (_cameraX + WINSIZEX >= BACKDCSIZEX) _cameraX = BACKDCSIZEX - WINSIZEX;

	// end of ī�޶� ���� **********************************************************************************
}
