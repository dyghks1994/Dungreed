#pragma once
#include "gameNode.h"
#include "player.h"

class gameScene : public gameNode
{
private:
	image* map;						// 배경 이미지
	player* _player;				// 플레이어 이미지
	
	
	RECT _rc;						// 테스트용 RECT
	int _x, _y;						// 플레이어 x, y 좌표
	int _cameraX, _cameraY;			// 카메라 x, y 좌표
	bool _cameraHorizontalMoveOk;	// 카메라의 좌우이동 가능 여부
	bool _cameraVerticalMoveOk;		// 카메라의 상하이동 가능 여부

public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void playerMove();
};

