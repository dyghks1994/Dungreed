#pragma once
#include "character.h"

class player : public character
{
	enum CHAR_STATE
	{
		UP,			// 캐릭터가 점프하면서 위로 올라가고 있는 상태
		LANDING,	// 캐릭터가 땅에 착지중인 상태
		DOWN,		// 캐릭터가 점프중에 아래로 하강하고 있는 상태
		DOWNJUMP,	// 캐릭터가 하단 점프를 사용하면서 땅(초록)과 겹쳐있는 상태
	};

private:
	CHAR_STATE _state;				// 현재 캐릭터의 상태를 저장

	image* _player;					// 플레이어 이미지

	RECT _rc;						// 테스트용 RECT
	float _x, _y;						// 플레이어 x, y 좌표
	float _jumpCount;					// 점프 횟수

	float _angle;					// 마우스 방향에 따른 각도 -> 대쉬와 공격에 사용
	
	bool  _dash;					// 대쉬 상태인지 판별하는 변수
	float _dashPower;				// 대쉬 파워
	float _dashCount;				// 대쉬하는 시간 카운트


	float _cameraX, _cameraY;			// 카메라 x, y 좌표

	float _probeI;					// 픽셀충돌 반복에 사용할 I 변수 -> 탐색 시작 지점
	float _probeY;					// 픽셀충돌에 사용할 탐사 Y 좌표 -> 탐색 끝 지점

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();		// 상하좌우 이동 및 점프
	void dash();		// 마우스 우클릭시 대쉬 기능
	bool pixelCollision(int probeY, int probeR, int probeG, int probeB);

	void cameraMove();
};

