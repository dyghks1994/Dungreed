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
	IMAGEMANAGER->addImage("맵", "image/gameScene/testMap.bmp", BACKDCSIZEX, BACKDCSIZEY, false, NULL);
	map = IMAGEMANAGER->findImage("맵");

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
	// 실제 배경(등)이미지와 캐릭터 이미지가 그려진 이미지(배경) -> source
	map->render(getMemDC(), map->getX(), map->getY());
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	// 카메라를 이용한 보여주기 렌더
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);
	
	
}

void gameScene::playerMove()
{
	// ************************************* 캐릭터 조정 **********************************************
	
	// 좌로 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3;	// 플레이어 x좌표 감소
		if (_cameraHorizontalMoveOk) _cameraX -= 3;	// 카메라 수평이동이 가능한 상태라면 카메라 x좌표 감소
	}

	// 우로 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3;	// 플레이어 x좌표 증가
		if (_cameraHorizontalMoveOk) _cameraX += 3; // 카메라 수평이동이 가능한 상태라면 카메라 x좌표 증가
	}

	// 위로 이동
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3;	// 플레이어 y좌표 감소
		if (_cameraVerticalMoveOk) _cameraY -= 3; // 카메라 수직이동이 가능한 상태라면 카메라 y좌표 감소
	}

	// 아래로 이동
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3;	// 플레이어 Y좌표 증가
		if (_cameraVerticalMoveOk) _cameraY += 3; // 카메라 수직이동이 가능한 상태라면 카메라 y좌표 증가
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= BACKDCSIZEX) _x = BACKDCSIZEX - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= BACKDCSIZEY) _y = BACKDCSIZEY - 25;

	_rc = RectMakeCenter(_x, _y, 50, 50);

	// end of 캐릭터 조정 *********************************************************************************


	// 카메라 조정 ****************************************************************************************
	// 카메라 좌우 이동 가능한지 판별
	if (_x <= 0 + WINSIZEX / 2 || _x >= BACKDCSIZEX - WINSIZEX / 2) _cameraHorizontalMoveOk = false;
	else _cameraHorizontalMoveOk = true;

	// 카메라 상하 이동 가능한지 판별
	if (_y <= 0 + WINSIZEY / 2 || _y >= BACKDCSIZEY - WINSIZEY / 2) _cameraVerticalMoveOk = false;
	else _cameraVerticalMoveOk = true;

	// 카메라가 맵을 벗어나지 않도록 위치 조정
	// 카메라가 왼쪽 끝에 있을 때
	if (_cameraX <= 0) _cameraX = 0;
	// 카메라가 오른쪽 끝에 있을 때
	if (_cameraX + WINSIZEX >= BACKDCSIZEX) _cameraX = BACKDCSIZEX - WINSIZEX;
	// 카메라가 위쪽 끝에 있을 때
	if (_cameraY <= 0) _cameraY = 0;
	// 카메라가 아래쪽 끝에 있을 때
	if (_cameraX + WINSIZEX >= BACKDCSIZEX) _cameraX = BACKDCSIZEX - WINSIZEX;

	// end of 카메라 조정 **********************************************************************************
}
