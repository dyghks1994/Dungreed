#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame() {}

mainGame::~mainGame() {}

//�ʱ�ȭ
HRESULT mainGame::init(void)
{
	//upcasting : �θ�Ŭ������ �ڽ�Ŭ�������� ȣ���Ѵ�
	gameNode::init(true);  //���ӳ���� init �Լ��� Ÿ�̸� ���� �� Ű�Ŵ��� �ʱ�ȭ ���� �Լ��� �����Ѵ�.
	
	
	_startScene = new startScene;					// ��ŸƮ �� �����Ҵ�
	_startScene->init();							// ��ŸƮ �� �ʱ�ȭ
	SCENEMANAGER->addScene("��ŸƮ��", _startScene);	// ��ŸƮ ��, �� ����Ʈ�� ���

	_gameScene = new gameScene;						// ���� �� �����Ҵ�
	SCENEMANAGER->addScene("���Ӿ�", _gameScene);	// ���� ��, �� ����Ʈ�� ���


	SCENEMANAGER->changeScene("��ŸƮ��");			// ó�� �����ϸ� ��ŸƮ������ ����

	return S_OK;
}

//�޸� ����
void mainGame::release(void)
{
	gameNode::release(); 
}

//������ ���⼭ �Ѵ�
void mainGame::update(void)
{
	gameNode::update();  

	SCENEMANAGER->update();
	
}

//�׸��� ���� ���� ���⿡��
void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, BACKDCSIZEX, BACKDCSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	
	SCENEMANAGER->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}