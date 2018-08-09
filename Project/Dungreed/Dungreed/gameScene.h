#pragma once
#include "gameNode.h"
#include "player.h"

class gameScene : public gameNode
{
private:
	image* map;
	player* _player;
	
	
	RECT _rc;
	int _x, _y;
	int _cameraX, _cameraY;

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

