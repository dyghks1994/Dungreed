#pragma once
#include "gameNode.h"
class startScene : public gameNode
{
public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

