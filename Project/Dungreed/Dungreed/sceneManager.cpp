#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"

//����ƽ���� ���� �Ǿ������Ƿ� �ʱ�ȭ�� ���⼭
gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;
sceneManager::sceneManager()
{
}

sceneManager::~sceneManager()
{
}

HRESULT sceneManager::init(void)
{
	_currentScene = NULL;
	_loadingScene = NULL;
	_readyScene = NULL;

	return S_OK;
}

void sceneManager::release(void)
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			//���� ���� ���ư��� ���� ���
			if (miSceneList->second == _currentScene)
			{
				miSceneList->second->release();
			}
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}
	_mSceneList.clear();
}

void sceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}

//�� �߰� �Լ�
gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}
//�� ����
HRESULT sceneManager::changeScene(string sceneName)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����Ͱ� ���� ������ ���� == ã���� �ϴ°� ���� 
	if (find == _mSceneList.end()) return E_FAIL;

	if (find->second == _currentScene) return S_OK;

	//���࿡ ������� init�� �θ��� ���� ������ �ٲٸ� �ȴ�.
	//���������� ���� �ٲ�ٸ� init�Լ� ����
	if (SUCCEEDED(find->second->init()))
	{
		//���� ������� �ٸ� ���� �ִٸ� ���� ���ְ�
		if (_currentScene) _currentScene->release();

		//�ٲٷ��� ������ ü���� �Ѵ�.
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}
