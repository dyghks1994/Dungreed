#pragma once
#include "gameNode.h"
#include "player.h"

class dungeon : public gameNode
{
	player* _player;	// �������� �� �÷��̾�

public:
	dungeon();
	~dungeon();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

