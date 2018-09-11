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
	//IMAGEMANAGER->addImage("����_ǥ��", "image/gameScene/����_ǥ��.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));
	_map = IMAGEMANAGER->findImage("����_ǥ��");
	_map->setX(0);
	_map->setY(0);
	
	//IMAGEMANAGER->addImage("����_����", "image/gameScene/����_����.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));

	_player = new player;
	_player->init(700.0f, 700.0f);
	
	return S_OK;
}

void gameScene::release()
{
}

void gameScene::update()
{
	_player->update();
	
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		
	}
}

void gameScene::render()
{
	// ���� ���(��)�̹����� ĳ���� �̹����� �׷��� �̹���(���) -> source
	_map->render(getMemDC(), _map->getX(), _map->getY());
	
	IMAGEMANAGER->findImage("����_����")->render(getMemDC());
	
	_player->render();
	
}
