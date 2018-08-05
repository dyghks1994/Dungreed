#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>           mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;  // ���� ��
	static gameNode* _loadingScene;	 // �ε� ��
	static gameNode* _readyScene;	 // ��� ��

	mapSceneList _mSceneList;
	mapSceneList _mnLoadingSceneList;
public:
	sceneManager();
	~sceneManager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//�� �߰� �Լ�
	gameNode* addScene(string sceneName, gameNode* scene);
	//�� ����
	HRESULT changeScene(string sceneName);
};

