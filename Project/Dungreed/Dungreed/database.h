#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

//����ü == public���θ� ������ Ŭ����
class elements
{
public:
	const char* name;
	int currentHP;
	int maxHP;
	float angle;
	float accelaration;
	float maxSpeed;

	elements() {};
	~elements() {};
};

class database : public singletonBase<database>
{
private:
	typedef vector<string>           arrElements;
	typedef vector<string>::iterator iterElements;

	typedef map<string, elements*>           arrElement;
	typedef map<string, elements*>::iterator iterElement;

private:
	arrElement _mTotalElement;
	float _angle;
public:
	database() {}
	~database() {}

	HRESULT init();
	void release();

	void loadDatabase(string name);

	//�Ӽ��� ���� ������
	elements* getElementData(string str)
	{
		return _mTotalElement.find(str)->second;
	}

	//����ä��
	void setElementDataCurrentHP(string str, float ch);
	//�ִ�ü��
	void setElementDataMaxHP(string str, float mh);
	//����
	void setElementDataAngle(string str, float a);
	//���ӵ�
	void setElementDataAccelaration(string str, float accel);
	//�ִ뽺�ǵ�
	void setElementDataMaxSpeed(string str, float ms);

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }
};

