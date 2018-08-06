#pragma once
#include "gameNode.h"

#include "startScene.h"
#include "gameScene.h"

class mainGame : public gameNode
{
private:
	gameNode* _startScene;		// 스타트 씬(시작화면)
	gameNode* _gameScene;		// 게임 씬(메인)
	

public:
	mainGame();
	~mainGame();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
};

