#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init()
{
	// 사용할 이미지 등록
	IMAGEMANAGER->addImage("시작화면", "image/intro.bmp", WINSIZEX, WINSIZEY, false, NULL);
	IMAGEMANAGER->addImage("게임시작_그레이", "image/button_gamestart_gray.bmp", 180, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("게임시작_화이트", "image/button_gamestart_white.bmp", 180, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("설정_그레이", "image/button_setting_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("설정_화이트", "image/button_setting_white.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("종료_그레이", "image/button_end_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("종료_화이트", "image/button_end_white.bmp", 100, 80, true, RGB(255, 0, 255));

	// 이미지 위치 설정
	IMAGEMANAGER->findImage("게임시작_그레이")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("게임시작_그레이")->getWidth() / 2);
	IMAGEMANAGER->findImage("게임시작_그레이")->setY(WINSIZEY / 2 + 100);
	IMAGEMANAGER->findImage("게임시작_화이트")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("게임시작_화이트")->getWidth() / 2);
	IMAGEMANAGER->findImage("게임시작_화이트")->setY(WINSIZEY / 2 + 100);

	IMAGEMANAGER->findImage("설정_그레이")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("설정_그레이")->getWidth() / 2);
	IMAGEMANAGER->findImage("설정_그레이")->setY(WINSIZEY / 2 + 200);
	IMAGEMANAGER->findImage("설정_화이트")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("설정_화이트")->getWidth() / 2);
	IMAGEMANAGER->findImage("설정_화이트")->setY(WINSIZEY / 2 + 200);

	IMAGEMANAGER->findImage("종료_그레이")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("종료_그레이")->getWidth() / 2);
	IMAGEMANAGER->findImage("종료_그레이")->setY(WINSIZEY / 2 + 280);
	IMAGEMANAGER->findImage("종료_화이트")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("종료_화이트")->getWidth() / 2);
	IMAGEMANAGER->findImage("종료_화이트")->setY(WINSIZEY / 2 + 280);

	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	// 종료버튼에 마우스가 올라가 있고 마우스 왼클릭이 되면
	if (PtInRect(&IMAGEMANAGER->findImage("종료_화이트")->collisionBox(), _ptMouse) && _leftButtonDown) 
	{
		PostQuitMessage(0);	// 종료메세지 전송
	}
}

void startScene::render()
{
	IMAGEMANAGER->findImage("시작화면")->render(getMemDC(), 0, 0);


	IMAGEMANAGER->findImage("게임시작_그레이")->render(getMemDC(), IMAGEMANAGER->findImage("게임시작_그레이")->getX(), IMAGEMANAGER->findImage("게임시작_그레이")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("게임시작_그레이")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("게임시작_화이트")->render(getMemDC(), IMAGEMANAGER->findImage("게임시작_화이트")->getX(), IMAGEMANAGER->findImage("게임시작_화이트")->getY());
	}

	IMAGEMANAGER->findImage("설정_그레이")->render(getMemDC(), IMAGEMANAGER->findImage("설정_그레이")->getX(), IMAGEMANAGER->findImage("설정_그레이")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("설정_그레이")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("설정_화이트")->render(getMemDC(), IMAGEMANAGER->findImage("설정_화이트")->getX(), IMAGEMANAGER->findImage("설정_화이트")->getY());
	}

	IMAGEMANAGER->findImage("종료_그레이")->render(getMemDC(), IMAGEMANAGER->findImage("종료_그레이")->getX(), IMAGEMANAGER->findImage("종료_그레이")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("종료_그레이")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("종료_화이트")->render(getMemDC(), IMAGEMANAGER->findImage("종료_화이트")->getX(), IMAGEMANAGER->findImage("종료_화이트")->getY());
	}
}
