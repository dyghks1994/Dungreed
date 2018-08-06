#pragma once
#include "gameNode.h"
#include "player.h"

class gameScene : public gameNode
{
private:
	player _player;

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

