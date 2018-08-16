#include "stdafx.h"
#include "player.h"
#include "gameScene.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_x = 700;
	_y = 250;
	_rc = RectMakeCenter(_x, _y, 50, 50);

	_probeY = _rc.bottom + 10;

	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	move();
}

void player::render()
{
	Rectangle(this->getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	// ī�޶� �̿��� �����ֱ� ����
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);

	char str[100];
	sprintf_s(str, "%d %d %d %d", _x, _y, _cameraX, _cameraY);
	TextOut(getMemDC(), 50, 50, str, sizeof(str));
}

void player::move()
{
	// ************************************* ĳ���� ���� **********************************************

	_y += 30;

	// �·� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 30;	// �÷��̾� x��ǥ ����
	}

	// ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 30;	// �÷��̾� x��ǥ ����
	}

	// ���� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 90;	// �÷��̾� y��ǥ ����
	}

	// �Ʒ��� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 30;	// �÷��̾� Y��ǥ ����
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= gameScene::_map->getWidth()) _x = _map->getWidth() - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= _map->getHeight()) _y = _map->getHeight() - 25;

	_probeY = _rc.bottom + 10;
	pixelCollision(_probeY);

	_rc = RectMakeCenter(_x, _y, 50, 50);


	// end of ĳ���� ���� *********************************************************************************


	// ī�޶� ���� ****************************************************************************************
	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;

	// ********* ī�޶� ���� ����� �ʵ��� ��ġ ���� **********************

	// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
	if (_x - WINSIZEX / 2 <= 0) _cameraX = 0;
	// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
	if (_y - WINSIZEY / 2 <= 0) _cameraY = 0;
	// ĳ���Ͱ� ������ ���� ������� ī�޶� ���������� �̵��ϸ� �ȵ� ��
	if (_x + WINSIZEX / 2 >= _map->getWidth()) _cameraX = _map->getWidth() - WINSIZEX;
	//// ĳ���Ͱ� �Ʒ��� ���� ������� ī�޶� �Ʒ������� �̵��ϸ� �ȵ� ��
	if (_y + WINSIZEY / 2 >= _map->getWidth()) _cameraY = _map->getHeight() - WINSIZEY;

	// end of ī�޶� ���� **********************************************************************************
}

bool player::pixelCollision(int probeY)
{
	for (int i = probeY - 30; i <= probeY + 30; ++i)
	{
		/*
		COLORREF = RGB������ ǥ��
		GetPixel = Ư�� ��ġ�� (X,Y)�� �ִ� �ȼ���
		RGB���� �����ش�. ���۾��� �ϱ� ���ؼ��� SELECT��
		��Ʈ���� ���������� �ľ��ϰ� ��Ʈ���� �̹��� ���۸�
		���� �ش� ��ġ�� �����ϴ� BYTE���� �����Ͽ�
		RGB���� �M
		*/
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("����_����")->getMemDC(), _x, i);

		//GetR(G)(B)Value  = ���� ��� �ڵ�
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - 25;
			break;
		}
	}

	return false;
}
