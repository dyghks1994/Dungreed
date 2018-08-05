#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame() {}

mainGame::~mainGame() {}

//초기화
HRESULT mainGame::init(void)
{
	//upcasting : 부모클래스를 자식클래스에서 호출한다
	gameNode::init(true);  //게임노드의 init 함수에 타이머 셋팅 및 키매니져 초기화 관련 함수를 실행한다.
	
	

	_startScene = new startScene;	// 스타트 씬 동적할당
	_startScene->init();			// 스타트 씬 초기화

	return S_OK;
}

//메모리 해제
void mainGame::release(void)
{
	gameNode::release(); //손대지 마셈
}

//연산은 여기서 한다
void mainGame::update(void)
{
	gameNode::update();  //손대지 마셈

	_startScene->update();
	
}

//그리는 것은 이제 여기에다
void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================
	
	_startScene->render();

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}