// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "KeyManager.h"
#include "utiles.h"
#include "imageManager.h"
#include "collision.h"
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"


using namespace std;
using namespace YoKing_UTIL;
/*
#define WINNAME (LPTSTR)TEXT("YoKing API")
#define WINSTARTX 2000
#define WINSTARTY 50
#define WINSIZEX 800
#define WINSIZEY 800
#define WINSTYLE WS_CAPTION | WS_SYSMENU
*/
#define WINNAME (LPTSTR)TEXT("YoKing API")

//풀스크린을 적용하려면 밑의 주석을 푸시오
//#define FULLSCREEN

#ifdef FULLSCREEN

#define WINSTARTX 0
#define WINSTARTY 0
#define WINSIZEX GetSystemMetrics(SM_CXSCREEN)
#define WINSIZEY GetSystemMetrics(SM_CXSCREEN)

#else

#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX 1000
#define WINSIZEY 700
#define BACKDCSIZEX 13512
#define BACKDCSIZEY 2576

#endif // FULLSCREEN

#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND             randomFunction::getSingleton()
#define KEYMANAGER      KeyManager::getSingleton()
#define IMAGEMANAGER    imageManager::getSingleton()
#define TXTDATA			txtData::getSingleton()
#define SOUNDMANAGER	soundManager::getSingleton()
#define TIMEMANAGER		timeManager::getSingleton()
#define EFFECTMANAGER   effectManager::getSingleton()
#define INIDATA			iniDataManager::getSingleton()
#define SCENEMANAGER    sceneManager::getSingleton()
#define DATABASE        database::getSingleton()

//안전한 메모리 관리
#define SAFE_DELETE(p) { if(p) {delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL; }}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
extern HINSTANCE	_hInstance;		//인스턴스 핸들
extern HWND			_hWnd;			//핸들
extern POINT        _ptMouse;       //마우스
extern BOOL         _leftButtonDown;
extern BOOL			_rightButtonDown;
extern image*		_map;
extern image*		_mapLand;
