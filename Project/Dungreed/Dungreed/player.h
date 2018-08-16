#pragma once
#include "character.h"

class player : public character, public gameScene
{
private:
	image* _player;					// 플레이어 이미지

	RECT _rc;						// 테스트용 RECT
	int _x, _y;						// 플레이어 x, y 좌표
	int _cameraX, _cameraY;			// 카메라 x, y 좌표

	int _probeY;					// 픽셀충돌에 사용할 탐사 Y 좌표

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	bool pixelCollision(int probeY);
};

