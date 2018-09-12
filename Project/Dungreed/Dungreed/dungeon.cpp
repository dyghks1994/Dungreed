#include "stdafx.h"
#include "dungeon.h"


dungeon::dungeon()
{
}


dungeon::~dungeon()
{
}

HRESULT dungeon::init()
{
	_map = IMAGEMANAGER->findImage("�׽�Ʈ");
	_map->setX(0);
	_map->setY(0);

	_player = new player;			// ���� �÷��̾� �����Ҵ�
	_player->init(500.0f, 500.0f);	// �÷��̾� x, y �� �Ѱ��ְ� �ش� ��ǥ�� �ʱ�ȭ

	return S_OK;
}

void dungeon::release()
{
}

void dungeon::update()
{
	_player->update();
}

void dungeon::render()
{
	_map->render(getMemDC(), _map->getX(), _map->getY());
	
	_player->render();
}
