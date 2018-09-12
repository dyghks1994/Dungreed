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
	_map = IMAGEMANAGER->findImage("����_ǥ��");
	_map->setX(0);
	_map->setY(0);

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
	
	

	// �ӽ÷� ����ȯ�� Ȯ���� ���� z Ű�� ������ �� �ٸ� ��(����)���� �̵��Ǵ��� Ȯ��
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		SCENEMANAGER->changeScene("����");
	}
}

void gameScene::render()
{
	// ���� ���(��)�̹����� ĳ���� �̹����� �׷��� �̹���(���) -> source
	_map->render(getMemDC(), _map->getX(), _map->getY());
	
	IMAGEMANAGER->findImage("����_����")->render(getMemDC());
	
	_player->render();
	
}

void gameScene::goDungeon()
{
	SCENEMANAGER->changeScene("����");
}
