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

	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3;
		_cameraX -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3;
		_cameraX += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3;
		_cameraY -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3;
		_cameraY += 3;
	}

	if (_x - 25 <= 0) _x = 25;
	if (_x + 25 >= BACKDCSIZEX) _cameraX = _x = BACKDCSIZEX - 25;
	if (_y - 25 <= 0) _y = 25;
	if (_y + 25 >= BACKDCSIZEY) _cameraY = _y = BACKDCSIZEY - 25;

	if (_cameraX <= 0) _cameraX = 0;
	if (_cameraY <= 0) _cameraY = 0;

	_rc = RectMakeCenter(_x, _y, 50, 50);
}

void gameScene::render()
{
	// 실제 배경(등)이미지와 캐릭터 이미지가 그려진 이미지(배경) -> source
	map->render(getMemDC(), map->getX(), map->getY());
	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	// 카메라를 이용한 보여주기 렌더
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);
	
	
}
