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
	
	// 카메라를 이용한 보여주기 렌더
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);

	char str[100];
	sprintf_s(str, "%d %d %d %d", _x, _y, _cameraX, _cameraY);
	TextOut(getMemDC(), 50, 50, str, sizeof(str));
}

void player::move()
{
	// ************************************* 캐릭터 조정 **********************************************

	_y += 30;

	// 좌로 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 30;	// 플레이어 x좌표 감소
	}

	// 우로 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 30;	// 플레이어 x좌표 증가
	}

	// 위로 이동
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 90;	// 플레이어 y좌표 감소
	}

	// 아래로 이동
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 30;	// 플레이어 Y좌표 증가
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


	// end of 캐릭터 조정 *********************************************************************************


	// 카메라 조정 ****************************************************************************************
	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;

	// ********* 카메라가 맵을 벗어나지 않도록 위치 조정 **********************

	// 캐릭터가 왼쪽 끝에 가까워져 카메라가 왼쪽으로 이동하면 안될 때
	if (_x - WINSIZEX / 2 <= 0) _cameraX = 0;
	// 캐릭터가 위쪽 끝에 가까워져 카메라가 위쪽으로 이동하면 안될 때
	if (_y - WINSIZEY / 2 <= 0) _cameraY = 0;
	// 캐릭터가 오른쪽 끝에 가까워져 카메라가 오른쪽으로 이동하면 안될 때
	if (_x + WINSIZEX / 2 >= _map->getWidth()) _cameraX = _map->getWidth() - WINSIZEX;
	//// 캐릭터가 아래쪽 끝에 가까워져 카메라가 아래쪽으로 이동하면 안될 때
	if (_y + WINSIZEY / 2 >= _map->getWidth()) _cameraY = _map->getHeight() - WINSIZEY;

	// end of 카메라 조정 **********************************************************************************
}

bool player::pixelCollision(int probeY)
{
	for (int i = probeY - 30; i <= probeY + 30; ++i)
	{
		/*
		COLORREF = RGB색상을 표현
		GetPixel = 특정 위치의 (X,Y)에 있는 픽셀의
		RGB값을 돌려준다. 이작업을 하기 위해서는 SELECT된
		비트맵의 정보구조를 파악하고 비트맵의 이미지 버퍼를
		얻어와 해당 위치에 존재하는 BYTE값을 조사하여
		RGB값을 뻄
		*/
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("마을_지형")->getMemDC(), _x, i);

		//GetR(G)(B)Value  = 색상값 출력 코드
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
