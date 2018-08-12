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
	IMAGEMANAGER->addImage("��", "image/gameScene/���׸���_����_����_�̹���.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));
	map = IMAGEMANAGER->findImage("��");
	map->setX(0);
	map->setY(0);

	IMAGEMANAGER->addImage("�浹", "image/gameScene/���׸���_����_����_�浹�ڽ�.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));

	_x = 700;
	_y = 250;
	_rc = RectMakeCenter(_x, _y, 50, 50);

	_probeY = _rc.bottom;

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
	
	IMAGEMANAGER->findImage("�浹")->render(getMemDC());
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	// ī�޶� �̿��� �����ֱ� ����
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);
	
	
}

void gameScene::playerMove()
{
	// ************************************* ĳ���� ���� **********************************************
	
	_y -= 3;

	// �·� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 30;	// �÷��̾� x��ǥ ����
		if (_cameraHorizontalMoveOk) _cameraX -= 30;	// ī�޶� �����̵��� ������ ���¶�� ī�޶� x��ǥ ����
	}

	// ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 30;	// �÷��̾� x��ǥ ����
		if (_cameraHorizontalMoveOk) _cameraX += 30; // ī�޶� �����̵��� ������ ���¶�� ī�޶� x��ǥ ����
	}

	// ���� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 30;	// �÷��̾� y��ǥ ����
		if (_cameraVerticalMoveOk) _cameraY -= 30; // ī�޶� �����̵��� ������ ���¶�� ī�޶� y��ǥ ����
	}

	// �Ʒ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 30;	// �÷��̾� Y��ǥ ����
		if (_cameraVerticalMoveOk) _cameraY += 30; // ī�޶� �����̵��� ������ ���¶�� ī�޶� y��ǥ ����
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= map->getWidth()) _x = map->getWidth() - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= map->getHeight()) _y = map->getHeight() - 25;

	_rc = RectMakeCenter(_x, _y, 50, 50);
	_probeY = _rc.bottom;

	pixelCollision(_probeY);

	// end of ĳ���� ���� *********************************************************************************


	// ī�޶� ���� ****************************************************************************************
	// ī�޶� �¿� �̵� �������� �Ǻ�
	if (_x <= 0 + WINSIZEX / 2 || _x >= map->getWidth() - WINSIZEX / 2) _cameraHorizontalMoveOk = false;
	else _cameraHorizontalMoveOk = true;

	// ī�޶� ���� �̵� �������� �Ǻ�
	if (_y <= 0 + WINSIZEY / 2 || _y >= map->getHeight() - WINSIZEY / 2) _cameraVerticalMoveOk = false;
	else _cameraVerticalMoveOk = true;

	
	// ********* ī�޶� ���� ����� �ʵ��� ��ġ ���� **********************
	
	// ī�޶� ���� ���� ���� ��
	if (_cameraX <= 0) _cameraX = 0;
	
	// ī�޶� ������ ���� ���� ��
	if (_cameraX + WINSIZEX >= map->getWidth()) _cameraX = map->getWidth() - WINSIZEX;
	
	// ī�޶� ���� ���� ���� ��
	if (_cameraY <= 0) _cameraY = 0;
	
	// ī�޶� �Ʒ��� ���� ���� ��
	if (_cameraY + WINSIZEY >= map->getHeight()) _cameraY = map->getHeight() - WINSIZEY;

	// end of ī�޶� ���� **********************************************************************************
}

bool gameScene::pixelCollision(int probeY)
{

	//for���� ���ؼ� Ž���� ���� ����
	//for (int i = probeY; i < probeY + 1; ++i)
	//{
		/*
		COLORREF = RGB������ ǥ��
		GetPixel = Ư�� ��ġ�� (X,Y)�� �ִ� �ȼ���
		RGB���� �����ش�. ���۾��� �ϱ� ���ؼ��� SELECT��
		��Ʈ���� ���������� �ľ��ϰ� ��Ʈ���� �̹��� ���۸�
		���� �ش� ��ġ�� �����ϴ� BYTE���� �����Ͽ�
		RGB���� �M
		*/
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("�浹")->getMemDC(), _x, _probeY + 1);

		//GetR(G)(B)Value  = ���� ��� �ڵ�
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 0 && g == 255 && b == 0))
		{
			_y = _probeY;
		//	break;
		}
		

	//}
	return false;
}
