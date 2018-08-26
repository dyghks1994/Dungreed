#include "stdafx.h"
#include "player.h"
#include "gameScene.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_state = DOWN;	// ���ۻ��� -> �ٿ�
	_probeY = (float)(_rc.bottom + 10.0f);	// �ٿ� ���¿��� Ž��Y ����

	_x = 700.0f;		// ������ġ X
	_y = 250.0f;		// ������ġ Y
	_rc = RectMakeCenter(_x, _y, 50, 50);

	_moveSpeed = 40.0f;			// �̵��ӵ� ����
	_jumpPower = 0.0f;			// �����Ŀ� �ʱ�ȭ
	_jumpCount = 0.0f;			// ����ī��Ʈ �ʱ�ȭ
	_gravity = 0.6f;			// �߷� ����

	_angle = getAngle(_x, _y, _ptMouse.x, _ptMouse.y);		// ���콺 ���⿡ ���� ���� ����

	_dash = false;				// ó���� �뽬 ���°� �ƴϰ� ����
	_dashPower = 200.0f;		// �뽬 �Ŀ� �ʱ�ȭ
	_dashCount = 0.0f;			// �뽬 �ð� ī���� �ʱ�ȭ
	
	_cameraX = _x - WINSIZEX / 2;	// ī�޶� X ��ǥ �ʱ�ȭ
	_cameraY = _y - WINSIZEY / 2;	// ī�޶� Y ��ǥ �ʱ�ȭ

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (_rightButtonDown && !_dash)
	{
		_dash = true;	// ���콺 ������ Ŭ���Ǹ� �뽬 ���·�
		_angle = getAngle(_x, _y, _ptMouse.x, _ptMouse.y);		// ���콺 ���⿡ ���� ���� ����
	}

	if(!_dash)
		move();		// ĳ������ �⺻ �����¿� �̵��� ���� ���
	
	if(_dash)
		dash();		// �뽬 ��� ȣ��

	//_y -= _jumpPower;			// ���� �����Ŀ� ��ŭ ĳ���� ����(���� �̵�)
	//_jumpPower -= _gravity;		// �����Ŀ��� �߷¿� ���� ������ ����
	
	cameraMove();
}

void player::render()
{
	// ���� ĳ���� ����
	Rectangle(this->getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	// ī�޶� �̿��� �����ֱ� ����
	_backBuffer->render(getMemDC(), 0, 0, _cameraX, _cameraY, WINSIZEX, WINSIZEY);

	// ��ǥ Ȯ��
	char str[100];
	sprintf_s(str, "%.0f %.d   %d    %f", _x, _rc.bottom, _state, _angle);
	TextOut(getMemDC(), 50, 50, str, sizeof(str));
}

void player::move()
{
	// ************************************* ĳ���� ���� **********************************************

	// �·� �̵�
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_x -= _moveSpeed;	// �÷��̾� x��ǥ ����
		if (_state == LANDING && !pixelCollision(_probeY, 0, 255, 0))
		{
			_state = DOWN;
			_probeI = (float)_rc.bottom;
			_probeY = (float)_rc.bottom + 50.0f;

			_gravity = 9.0f;
		}
	}

	// ��� �̵�
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_x += _moveSpeed;	// �÷��̾� x��ǥ ����
		if (_state == LANDING && !pixelCollision(_probeY, 0, 255, 0))
		{
			_state = DOWN;
			_probeI = (float)_rc.bottom;
			_probeY = (float)_rc.bottom + 50.0f;

			_gravity = 9.0f;
		}
	}

	// �Ʒ��� �̵�(����)
	if (KEYMANAGER->isStayKeyDown('S') && KEYMANAGER->isOnceKeyDown(VK_SPACE) && _state == LANDING)
	{
		// �ʷ� ���� ���� ���¿��� �ϴ� ������ �ϴ� ���
		if (pixelCollision(_probeY, 0, 255, 0))
		{
			_jumpPower = 0.0f;
			_gravity = 9.0f;

			_state = DOWNJUMP;			// �ϴ� ��������(DOWNJUMP)�� ����
		}
		
		// LANDING �������� ���� �ٴ� ������ �� �Ʒ��� �� �� ����

	}
	// ���� ����
	else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) || KEYMANAGER->isStayKeyDown('W'))
	{
		_state = UP;			// ��������(UP)�� ����

		_jumpPower = 50.0f;		// �����Ŀ� ����
		_gravity = 9.0f;		// �߷� ����

		_jumpCount++;			// ���� ī��Ʈ ����
	}

	
	_y -= _jumpPower;			// ���� �����Ŀ� ��ŭ ĳ���� ����(���� �̵�)
	_jumpPower -= _gravity;		// �����Ŀ��� �߷¿� ���� ������ ����
	if (_jumpPower < 0 && !pixelCollision(_probeY, 0,255, 0)) _state = DOWN;	// �����Ŀ��� 0���� �۾Ƽ� ĳ���Ͱ� �ϰ��� ��쿡 -> ���¸� �ٿ����� ����


	// ĳ���� ���¿� ���� �ȼ��浹(_probeY) ����
	if (_state == UP)
	{
		_probeI = (float)_rc.top;
		_probeY = (float)_rc.bottom;
	}
	if (_state == LANDING)
	{
		_probeI = (float)_rc.bottom - 100;
		_probeY = (float)_rc.bottom + 50;

		if (pixelCollision(_probeY, 0, 255, 0))
		{
			_y = _probeI - 25.0f;		// y��ǥ�� �� ���� ����
		}
	}

	// �ϰ� ����
	if (_state == DOWN)
	{
		_probeI = (float)_rc.bottom;
		_probeY = (float)_rc.bottom + 70.0f;

		if (pixelCollision(_probeY, 0, 255, 0))	// ��� �ٴڰ� �浹 �ߴ°�?
		{
			_jumpCount = 0;			// ��� �ٴ��� ������ ����ī��Ʈ�� 0���� -> �������·�
			_jumpPower = 0.0f;		// �����Ŀ� ����	
			_gravity = 0.0f;		// �Ʒ��� �������� �ʰ� �߷��� 0���� ����
		
			_y = _probeI - 25.0f;		// y��ǥ�� �� ���� ����
			_state = LANDING;		// ���� ���·� ����
		}

		_probeI = _rc.bottom;		// Ž�� ���� ��ġ �� ����
		if (pixelCollision(_probeY, 255, 0, 0)) // ���� �ٴڰ� �浹 �ߴ°�?
		{
			_jumpCount = 0;			// ���� �ٴ��� ������ ����ī��Ʈ�� 0���� -> �������·�
			_jumpPower = 0.0f;		// �����Ŀ� ����	
			_gravity = 0.0f;		// �Ʒ��� �������� �ʰ� �߷��� 0���� ����
		
			_y = _probeI - 25.0f;		// y��ǥ�� �� ���� ����
			_state = LANDING;		// ���� ���·� ����
		}
	}

	// �ϴ� ������ �ϰ� ���� ��
	if (_state == DOWNJUMP)
	{
		_probeI = (float)_rc.top;
		_probeY = (float)_rc.bottom;

		// ��� ���� �浹���� ��� ���
		if (!pixelCollision(_probeY, 0, 255, 0))
		{
			// �Ϲ� �ٿ� ���·� ����
			_state = DOWN;
		}
	}


	// ĳ������ �����¿� �� ��Ż ����
	if (_x - 25 <= 0.0f) _x = 25.0f;
	if (_x + 25 >= _map->getWidth()) _x = _map->getWidth() - 25.0f;
	if (_y - 25 <= 0.0f) _y = 25.0f;
	if (_y + 25 >= _map->getHeight()) _y = _map->getHeight() - 25.0f;

	_rc = RectMakeCenter(_x, _y, 50, 50);		// ���� ��ǥ�� ĳ������ �������� ��´�

	// end of ĳ���� ���� *********************************************************************************

}

void player::dash()
{	
	//if (!_dash) return;	// �뽬 ���°� �ƴϸ� �뽬���� �ʰ� ����

	_x += cosf(_angle) * _dashPower;
	_y += -sinf(_angle) * _dashPower;

	_dashCount += 110.0f;
	_gravity = 7.5f;

	if (_angle <= PI)
	{
		_state = UP;
		_probeI = (float)_rc.top;
		_probeY = (float)_rc.bottom;
	}
	if (_angle > PI)
	{
		_state = DOWNJUMP;
		_probeI = (float)_rc.top;
		_probeY = (float)_rc.bottom;

		if (pixelCollision(_probeY, 255, 0, 0)) // ���� �ٴڰ� �浹 �ߴ°�?
		{
			_jumpCount = 0;			// ���� �ٴ��� ������ ����ī��Ʈ�� 0���� -> �������·�
			_jumpPower = 0.0f;		// �����Ŀ� ����	
			_gravity = 0.0f;		// �Ʒ��� �������� �ʰ� �߷��� 0���� ����

			_y = _probeI - 25.0f;		// y��ǥ�� �� ���� ����
			_state = LANDING;		// ���� ���·� ����
		}
	}

	_rc = RectMakeCenter(_x, _y, 50, 50);		// ���� ��ǥ�� ĳ������ �������� ��´�

	if (_dashCount > 100.0f)
	{
		_dashCount = 0.0f;
		_dash = false;
	}
	
}

bool player::pixelCollision(int probeY, int probeR, int probeG, int probeB)
{
	for (; _probeI <= probeY; ++_probeI)
	{			
		/*
		COLORREF = RGB������ ǥ��
		GetPixel = Ư�� ��ġ�� (X,Y)�� �ִ� �ȼ���
		RGB���� �����ش�. ���۾��� �ϱ� ���ؼ��� SELECT��
		��Ʈ���� ���������� �ľ��ϰ� ��Ʈ���� �̹��� ���۸�
		���� �ش� ��ġ�� �����ϴ� BYTE���� �����Ͽ�
		RGB���� �M
		*/
		COLORREF color = GetPixel(_mapLand->getMemDC(), _x, _probeI);

		//GetR(G)(B)Value  = ���� ��� �ڵ�
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == probeR && g == probeG && b == probeB)
		{
			return true;		// �Ƚ� Ž�� ��� ���ϴ� ����� ��ġ��.			
		}
	}
	return false;	// �ȼ� Ž�� ��� ���ϴ� ����� �ٸ�
}

void player::cameraMove()
{
	// ī�޶� ���� ****************************************************************************************
	_cameraX = _x - WINSIZEX / 2;
	_cameraY = _y - WINSIZEY / 2;

	// ********* ī�޶� ���� ����� �ʵ��� ��ġ ���� **********************

	// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
	if (_x - WINSIZEX / 2 <= 0) _cameraX = 0;
	// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
	if (_y - WINSIZEY / 2 <= 0) _cameraY = 0;
	// ĳ���Ͱ� ������ ���� ������� ī�޶� ���������� �̵��ϸ� �ȵ� ��
	if (_x + WINSIZEX / 2 >= _map->getWidth()) _cameraX = _map->getWidth() - WINSIZEX;
	//// ĳ���Ͱ� �Ʒ��� ���� ������� ī�޶� �Ʒ������� �̵��ϸ� �ȵ� ��
	if (_y + WINSIZEY / 2 >= _map->getWidth()) _cameraY = _map->getHeight() - WINSIZEY;

	// end of ī�޶� ���� **********************************************************************************
}
