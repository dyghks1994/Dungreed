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
	//IMAGEMANAGER->addImage("마을_표면", "image/gameScene/마을_표면.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));
	_map = IMAGEMANAGER->findImage("마을_표면");
	_map->setX(0);
	_map->setY(0);
	
	//IMAGEMANAGER->addImage("마을_지형", "image/gameScene/마을_지형.bmp", BACKDCSIZEX, BACKDCSIZEY, true, RGB(255, 0, 255));

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
	// 실제 배경(등)이미지와 캐릭터 이미지가 그려진 이미지(배경) -> source
	_map->render(getMemDC(), _map->getX(), _map->getY());
	
	IMAGEMANAGER->findImage("마을_지형")->render(getMemDC());
	
	_player->render();
	
}
