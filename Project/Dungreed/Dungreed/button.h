#pragma once
#include "gameNode.h"

typedef void(*CALLBACK_FUNCTION)(void);
//�ݹ��Լ� == �Լ������͸� �����ؼ� ������ ������ �ִٰ�
//�Լ������͸� �̿��ؼ� ȣ���� �� ���
//���� ȣ���� �Լ��� ����Ÿ�ӿ� �����ؼ� ����� ����

//���θ� �ϸ� �� ������ �ִ�
//<Functional> �̶�� ���̺귯���� �ִµ�
//���⿡ std::Function, std::move, std::bind ���
//�ݹ��Լ��� ���� �������� ������ static �����̹Ƿ�
//�Ű������� ����� �� ���� �����̴�.
//������ Functional ���̺귯���� �̿��Ѵٸ� �Ϲ� �Ű�������
//�ݹ��Լ��� �־ ����� �� �ִ�.

//����) �ǿܷ� ����
//����2) �ǿܷ� ��ޱ⵵ ���� 

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;
	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;
public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release(void);
	void update(void);
	void render(void);
};

