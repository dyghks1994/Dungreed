#pragma once
#include "gameNode.h"
#include "player.h"

class gameScene : public gameNode
{
private:
	player*	_player;	// 플레이어		

public:
	gameScene();
	~gameScene();

	image* _map;		// 배경 이미지

	HRESULT init();
	void release();
	void update();
	void render();
	
};

