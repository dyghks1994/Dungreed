#pragma once
class character
{
private:
	image*	_image;		  // ĳ���� �̹���

	int		_maxHp;		  // �ִ� �����
	int		_currentHp;	  // ���� �����
	int		_atk;		  // ���ݷ�
	int		_def;		  // ����
	float	_moveSpeed;	  // �̵��ӵ�
	float	_jumpPower;	  // ������
	float	_atkSpeed;	  // ���ݼӵ�

public:
	character();
	~character();

	// getter setter
	int getMaxHp() { return _maxHp; }
	void setMaxHp(int maxHp) { _maxHp = maxHp; }
	int getCurrentHp() { return _currentHp; }
	void setCurrnetHp(int currentHp) { _maxHp = currentHp; }

	int getAtk() { return _atk; }
	void setAtk(int atk) { _atk = atk; }

	int getDef() { return _def; }
	void setDef(int def) { _def = def; }

	float getMoveSpeed() { return _moveSpeed; }
	void setMoveSpeed(float moveSpeed) { _moveSpeed = moveSpeed; }

	float getJumpPower() { return _jumpPower; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }

	float getAtkSpeed() { return _atkSpeed; }
	void setAtkSpeed(float atkSpeed) { _atkSpeed = atkSpeed; }

};

