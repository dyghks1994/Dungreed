#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);//�߰�

																					 //�ڽ������� �޽��� ���� ������ ���� �̳ѹ�
enum CTRL
{
	CTRL_SAVE,         //���̺� ��ư�޼���
	CTRL_LOAD,		   //�ε� ��ư�޼���
	CTRL_TERRAINDRAW,  //���� ��ư�޼���
	CTRL_OBJDRAW,	   //������Ʈ ��ư�޼���
	CTRL_ERASER,	   //���찳 ��ư�޼���
	CTRL_END
};
class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;		         //�Ŵ������� �ʱ�ȭ �� ���̳�
public:
	int _ctrSelect;                 //��Ʈ�� ��ư ���� �Լ�
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);	    //�׷��ִ� �Լ�

	virtual void setMap(void);
	virtual void save(void);
	virtual void load(void);

	void setCtrlSelect(int num) { _ctrSelect = num; }

	image* getBackBuffer(void) { return _backBuffer; }
	//MemDC -> ������ִ� �޸� ��Ȱ
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }


	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

