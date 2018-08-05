#include "stdafx.h"
#include "action.h"

HRESULT action::init()
{
	_worldTimeCount = 0;
	_isMoving = false;

	return S_OK;
}

void action::release()
{
}

void action::update()
{
	moving();
}

void action::render()
{
}

void action::moveTo(image * image, float endX, float endY, float time)
{
	if (!_isMoving)
	{
		_image = image;

		_endX = endX;
		_endY = endY;

		_startX = image->getX();
		_startY = image->getY();

		//������������ ������������ �Ÿ��� ���Ѵ�.
		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		//������������ ���������� ���󰡾ߵ� ��ü ����
		_angle = getAngle(_startX, _startY, _endX, _endY);

		//_worldTimeCount�� Ÿ�ӸŴ����� ���� ���� �ִ´�.
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;
	}
}

void action::moving(void)
{
	if (!_isMoving) return;

	//����ð�
	float elapseTime = TIMEMANAGER->getElapsedTime();

	//�ӵ����ϴ� ��
	float moveSpeed = (elapseTime / _time) * _travelRange;
	//     ���ӵ�   =  (ƽī����(0.001) / �ҿ�ð� * �Ÿ�

	//�̹��� x y �� �����̰� ����
	_image->setX(_image->getX() + cosf(_angle) * moveSpeed);
	_image->setY(_image->getY() + -sinf(_angle) * moveSpeed);

	//�̹��� x y�� ���������� ���� ������
	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_image->setX(_endX);
		_image->setY(_endY);

		_isMoving = false;
	}
}
