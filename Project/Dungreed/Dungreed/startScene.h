#pragma once
#include "gameNode.h"
class startScene : public gameNode
{
private:
	image* _btnGameStartGray;		// ���ӽ��� ��ư ȸ��
	image* _btnGameStartWhite;		// ���ӽ��� ��ư ���
	image* _btnSettingGray;			// ���� ��ư ȸ��
	image* _btnSettingWhite;		// ���� ��ư ���
	image* _btnEndGray;				// ���� ��ư ȸ��
	image* _btnEndWhite;			// ���� ��ư ���

public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

