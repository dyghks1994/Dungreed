#pragma once
#include "gameNode.h"

#include "startScene.h"

class mainGame : public gameNode
{
private:
	gameNode* _startScene;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
};

