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
	_map = IMAGEMANAGER->findImage("Å×½ºÆ®");
	_map->setX(0);
	_map->setY(0);

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
	_backBuffer->render(getMemDC(), _map->getX(), _map->getY());
	
	_player->render();
}
