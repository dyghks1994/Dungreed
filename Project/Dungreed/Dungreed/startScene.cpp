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
	IMAGEMANAGER->addImage("����ȭ��", "image/startScene/intro.bmp", WINSIZEX, WINSIZEY, false, NULL);

	IMAGEMANAGER->addImage("���ӽ���_�׷���", "image/startScene/button_gamestart_gray.bmp", 180, 100, true, RGB(255, 0, 255));
	_btnGameStartGray = IMAGEMANAGER->findImage("���ӽ���_�׷���");
	
	IMAGEMANAGER->addImage("���ӽ���_ȭ��Ʈ", "image/startScene/button_gamestart_white.bmp", 180, 100, true, RGB(255, 0, 255));
	_btnGameStartWhite = IMAGEMANAGER->findImage("���ӽ���_ȭ��Ʈ");

	IMAGEMANAGER->addImage("����_�׷���", "image/startScene/button_setting_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	_btnSettingGray = IMAGEMANAGER->findImage("����_�׷���");

	IMAGEMANAGER->addImage("����_ȭ��Ʈ", "image/startScene/button_setting_white.bmp", 100, 80, true, RGB(255, 0, 255));
	_btnSettingWhite = IMAGEMANAGER->findImage("����_ȭ��Ʈ");

	IMAGEMANAGER->addImage("����_�׷���", "image/startScene/button_end_gray.bmp", 100, 80, true, RGB(255, 0, 255));
	_btnEndGray = IMAGEMANAGER->findImage("����_�׷���");

	IMAGEMANAGER->addImage("����_ȭ��Ʈ", "image/startScene/button_end_white.bmp", 100, 80, true, RGB(255, 0, 255));
	_btnEndWhite = IMAGEMANAGER->findImage("����_ȭ��Ʈ");

	


	// *****************************
	// *                           *
	// *     �̹��� ��ġ ����       *
	// *                           *
	// *****************************
	// ���ӽ��� ��ư ������ ����
	_btnGameStartGray->setX(WINSIZEX / 2 - _btnGameStartGray->getWidth() / 2);
	_btnGameStartGray->setY(WINSIZEY / 2 + 100);
	_btnGameStartWhite->setX(WINSIZEX / 2 - _btnGameStartWhite->getWidth() / 2);
	_btnGameStartWhite->setY(WINSIZEY / 2 + 100);

	// ���� ��ư ������ ����
	_btnSettingGray->setX(WINSIZEX / 2 - _btnSettingGray->getWidth() / 2);
	_btnSettingGray->setY(WINSIZEY / 2 + 200);
	_btnSettingWhite->setX(WINSIZEX / 2 - _btnSettingWhite->getWidth() / 2);
	_btnSettingWhite->setY(WINSIZEY / 2 + 200);

	// ���� ��ư ������ ����
	_btnEndGray->setX(WINSIZEX / 2 - _btnEndGray->getWidth() / 2);
	_btnEndGray->setY(WINSIZEY / 2 + 280);
	_btnEndWhite->setX(WINSIZEX / 2 - _btnEndWhite->getWidth() / 2);
	_btnEndWhite->setY(WINSIZEY / 2 + 280);

	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	// ���ӽ��� ��ư�� ���콺�� �ö� �ְ� ���콺 ��Ŭ���� �Ǹ�
	if (PtInRect(&_btnGameStartWhite->collisionBox(), _ptMouse) && _leftButtonDown)
	{
		SCENEMANAGER->changeScene("���Ӿ�");
	}

	// �����ư�� ���콺�� �ö� �ְ� ���콺 ��Ŭ���� �Ǹ�
	if (PtInRect(&_btnEndWhite->collisionBox(), _ptMouse) && _leftButtonDown)
	{
		PostQuitMessage(0);	// ����޼��� ����
	}
}

void startScene::render()
{
	// ��ŸƮ �� ���ȭ�� ����
	IMAGEMANAGER->findImage("����ȭ��")->render(getMemDC(), 0, 0);

	// ���ӽ��� ��ư ����
	_btnGameStartGray->render(getMemDC(), _btnGameStartGray->getX(), _btnGameStartGray->getY());
	if (PtInRect(&_btnGameStartGray->collisionBox(), _ptMouse))
	{
		_btnGameStartWhite->render(getMemDC(), _btnGameStartWhite->getX(), _btnGameStartWhite->getY());
	}

	// ���� ��ư ����
	_btnSettingGray->render(getMemDC(), _btnSettingGray->getX(), _btnSettingGray->getY());
	if (PtInRect(&_btnSettingGray->collisionBox(), _ptMouse))
	{
		_btnSettingWhite->render(getMemDC(), _btnSettingWhite->getX(), _btnSettingWhite->getY());
	}

	// ���� ��ư ����
	_btnEndGray->render(getMemDC(), _btnEndGray->getX(), _btnEndGray->getY());
	if (PtInRect(&_btnEndGray->collisionBox(), _ptMouse))
	{
		_btnEndWhite->render(getMemDC(), _btnEndWhite->getX(), _btnEndWhite->getY());
	}
}
