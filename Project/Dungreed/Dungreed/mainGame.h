#pragma once
#include "gameNode.h"

#include "startScene.h"
#include "gameScene.h"

class mainGame : public gameNode
{
private:
	gameNode* _startScene;		// ��ŸƮ ��(����ȭ��)
	gameNode* _gameScene;		// ���� ��(����)
	

public:
	mainGame();
	~mainGame();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();
};

