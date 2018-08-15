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
	IMAGEMANAGER->addImage("마을_표면", "image/gameScene/마을_표면.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));
	map = IMAGEMANAGER->findImage("마을_표면");
	map->setX(0);
	map->setY(0);

	IMAGEMANAGER->addImage("마을_지형", "image/gameScene/마을_지형.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));

	_x = 700;
	_y = 250;
	_rc = RectMakeCenter(_x, _y, 50, 50);

	_probeY = _rc.bottom + 10;

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
	
	IMAGEMANAGER->findImage("마을_지형")->render(getMemDC());
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	// 카메라를 이용한 보여주기 렌더
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);
	
	char str[100];
	sprintf_s(str, "%d", _y);
	TextOut(getMemDC(), 50, 50, str, sizeof(str));
	
}

void gameScene::playerMove()
{
	// ************************************* 캐릭터 조정 **********************************************
	
	_y += 30;

	// 좌로 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 30;	// 플레이어 x좌표 감소
		//if (_cameraHorizontalMoveOk) _cameraX -= 30;	// 카메라 수평이동이 가능한 상태라면 카메라 x좌표 감소
	}

	// 우로 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 30;	// 플레이어 x좌표 증가
		//if (_cameraHorizontalMoveOk) _cameraX += 30; // 카메라 수평이동이 가능한 상태라면 카메라 x좌표 증가
	}

	// 위로 이동
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 90;	// 플레이어 y좌표 감소
		//if (_cameraVerticalMoveOk) _cameraY -= 90; // 카메라 수직이동이 가능한 상태라면 카메라 y좌표 감소
	}

	// 아래로 이동
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 30;	// 플레이어 Y좌표 증가
		//if (_cameraVerticalMoveOk) _cameraY += 30; // 카메라 수직이동이 가능한 상태라면 카메라 y좌표 증가
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= map->getWidth()) _x = map->getWidth() - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= map->getHeight()) _y = map->getHeight() - 25;

	_probeY = _rc.bottom;
	pixelCollision(_probeY);

	_rc = RectMakeCenter(_x, _y, 50, 50);
	
	
	// end of 캐릭터 조정 *********************************************************************************


	// 카메라 조정 ****************************************************************************************
	// 카메라 좌우 이동 가능한지 판별
	//if (_x <= 0 + WINSIZEX / 2 || _x >= map->getWidth() - WINSIZEX / 2) _cameraHorizontalMoveOk = false;
	//else _cameraHorizontalMoveOk = true;
	//
	//// 카메라 상하 이동 가능한지 판별
	//if (_y <= 0 + WINSIZEY / 2 || _y >= map->getHeight() - WINSIZEY / 2) _cameraVerticalMoveOk = false;
	//else _cameraVerticalMoveOk = true;

	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;

	// 캐릭터가 왼쪽 끝에 가까워져 카메라가 왼쪽으로 이동하면 안될 때
	if (_x - WINSIZEX / 2 <= 0) _cameraX = 0;
	// 캐릭터가 위쪽 끝에 가까워져 카메라가 위쪽으로 이동하면 안될 때
	if (_y - WINSIZEY / 2 <= 0) _cameraY = 0;
	// 캐릭터가 오른쪽 끝에 가까워져 카메라가 오른쪽으로 이동하면 안될 때
	if (_x + WINSIZEX / 2 <= map->getWidth()) _cameraX = map->getWidth() - WINSIZEX;
	// 캐릭터가 아래쪽 끝에 가까워져 카메라가 아래쪽으로 이동하면 안될 때
	if (_y + WINSIZEY / 2 <= 0) _cameraY = map->getHeight() - WINSIZEY;



	
	// ********* 카메라가 맵을 벗어나지 않도록 위치 조정 **********************
	
	// 카메라가 왼쪽 끝에 있을 때
	//if (_cameraX <= 0) _cameraX = 0;
	//
	//// 카메라가 오른쪽 끝에 있을 때
	//if (_cameraX + WINSIZEX >= map->getWidth()) _cameraX = map->getWidth() - WINSIZEX;
	//
	//// 카메라가 위쪽 끝에 있을 때
	//if (_cameraY <= 0) _cameraY = 0;
	//
	//// 카메라가 아래쪽 끝에 있을 때
	//if (_cameraY + WINSIZEY >= map->getHeight()) _cameraY = map->getHeight() - WINSIZEY;

	// end of 카메라 조정 **********************************************************************************
}

bool gameScene::pixelCollision(int probeY)
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
