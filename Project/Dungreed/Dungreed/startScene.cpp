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
	// ����� �̹��� ���
	IMAGEMANAGER->addImage("����ȭ��", "image/intro.bmp", WINSIZEX, WINSIZEY, false, NULL);
	IMAGEMANAGER->addImage("���ӽ���_�׷���", "image/button_gamestart_gray.bmp", 180, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ӽ���_ȭ��Ʈ", "image/button_gamestart_white.bmp", 180, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����_�׷���", "image/button_setting_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����_ȭ��Ʈ", "image/button_setting_white.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����_�׷���", "image/button_end_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����_ȭ��Ʈ", "image/button_end_white.bmp", 100, 80, true, RGB(255, 0, 255));

	// �̹��� ��ġ ����
	IMAGEMANAGER->findImage("���ӽ���_�׷���")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("���ӽ���_�׷���")->getWidth() / 2);
	IMAGEMANAGER->findImage("���ӽ���_�׷���")->setY(WINSIZEY / 2 + 100);
	IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->getWidth() / 2);
	IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->setY(WINSIZEY / 2 + 100);

	IMAGEMANAGER->findImage("����_�׷���")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("����_�׷���")->getWidth() / 2);
	IMAGEMANAGER->findImage("����_�׷���")->setY(WINSIZEY / 2 + 200);
	IMAGEMANAGER->findImage("����_ȭ��Ʈ")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getWidth() / 2);
	IMAGEMANAGER->findImage("����_ȭ��Ʈ")->setY(WINSIZEY / 2 + 200);

	IMAGEMANAGER->findImage("����_�׷���")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("����_�׷���")->getWidth() / 2);
	IMAGEMANAGER->findImage("����_�׷���")->setY(WINSIZEY / 2 + 280);
	IMAGEMANAGER->findImage("����_ȭ��Ʈ")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getWidth() / 2);
	IMAGEMANAGER->findImage("����_ȭ��Ʈ")->setY(WINSIZEY / 2 + 280);

	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	// �����ư�� ���콺�� �ö� �ְ� ���콺 ��Ŭ���� �Ǹ�
	if (PtInRect(&IMAGEMANAGER->findImage("����_ȭ��Ʈ")->collisionBox(), _ptMouse) && _leftButtonDown) 
	{
		PostQuitMessage(0);	// ����޼��� ����
	}
}

void startScene::render()
{
	IMAGEMANAGER->findImage("����ȭ��")->render(getMemDC(), 0, 0);


	IMAGEMANAGER->findImage("���ӽ���_�׷���")->render(getMemDC(), IMAGEMANAGER->findImage("���ӽ���_�׷���")->getX(), IMAGEMANAGER->findImage("���ӽ���_�׷���")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("���ӽ���_�׷���")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->render(getMemDC(), IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->getX(), IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ")->getY());
	}

	IMAGEMANAGER->findImage("����_�׷���")->render(getMemDC(), IMAGEMANAGER->findImage("����_�׷���")->getX(), IMAGEMANAGER->findImage("����_�׷���")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("����_�׷���")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("����_ȭ��Ʈ")->render(getMemDC(), IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getX(), IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getY());
	}

	IMAGEMANAGER->findImage("����_�׷���")->render(getMemDC(), IMAGEMANAGER->findImage("����_�׷���")->getX(), IMAGEMANAGER->findImage("����_�׷���")->getY());
	if (PtInRect(&IMAGEMANAGER->findImage("����_�׷���")->collisionBox(), _ptMouse))
	{
		IMAGEMANAGER->findImage("����_ȭ��Ʈ")->render(getMemDC(), IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getX(), IMAGEMANAGER->findImage("����_ȭ��Ʈ")->getY());
	}
}
