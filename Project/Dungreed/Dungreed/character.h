#pragma once
class character
{
private:
	image*	_image;		  // 캐릭터 이미지
	int		_hp;		  // 생명력
	int		_attack;	  // 공격력
	int		_def;		  // 방어력
	float	_moveSpeed;	  // 이동속도
	float	_jumpPower;	  // 점프력
	float	_attackSpeed; // 공격속도

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

