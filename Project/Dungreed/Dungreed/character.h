#pragma once
class character
{
private:
	image*	_image;		  // ĳ���� �̹���
	int		_hp;		  // �����
	int		_attack;	  // ���ݷ�
	int		_def;		  // ����
	float	_moveSpeed;	  // �̵��ӵ�
	float	_jumpPower;	  // ������
	float	_attackSpeed; // ���ݼӵ�

public:
	character();
	~character();

	// getter setter
	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	int getAttack() { return _attack; }
	void setAttack(int attack) { _attack = attack; }

	int getDef() { return _def; }
	void setDef(int def) { _def = def; }

	float getMoveSpeed() { return _moveSpeed; }
	void setMoveSpeed(float moveSpeed) { _moveSpeed = moveSpeed; }

	float getJumpPower() { return _jumpPower; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }

	float getAttackSpeed() { return _attackSpeed; }
	void setAttackSpeed(float attackSpeed) { _attackSpeed = attackSpeed; }

};

