#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame() {}

mainGame::~mainGame() {}

//�ʱ�ȭ
HRESULT mainGame::init(void)
{
	//upcasting : �θ�Ŭ������ �ڽ�Ŭ�������� ȣ���Ѵ�
	gameNode::init(true);  //���ӳ���� init �Լ��� Ÿ�̸� ���� �� Ű�Ŵ��� �ʱ�ȭ ���� �Լ��� �����Ѵ�.
	
	

	_startScene = new startScene;	// ��ŸƮ �� �����Ҵ�
	_startScene->init();			// ��ŸƮ �� �ʱ�ȭ

	return S_OK;
}

//�޸� ����
void mainGame::release(void)
{
	gameNode::release(); //�մ��� ����
}

//������ ���⼭ �Ѵ�
void mainGame::update(void)
{
	gameNode::update();  //�մ��� ����

	_startScene->update();
	
}

//�׸��� ���� ���� ���⿡��
void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	
	_startScene->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}