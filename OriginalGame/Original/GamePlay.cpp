#include "COriginalGameApp.h"
#include "GameResource.h"
#include "CPlayer.h"
#include "CTimer.h"

#define PI 3.14

//変数定義-----------------------------------------------------------------------
//ゲーム画面のフェーズを管理する変数
ePhase g_GamePhase = eBegin;
//背景の画像を管理する変数
CPicture* g_pBackground = NULL;

CPicture* g_pLoading = NULL;

//ゲーム画面から次へ進むときのフローを管理する変数
eGameStatus g_NextStatusFromGame = eNone;

//PLAYER-------------------------------------------------------------------------
CPlayer* g_pPlayer = NULL;

/*
 * ゲーム本編の処理を行う部分
 */

void COriginalGameApp::procGame(const float& _dt)
{

	//GamePhase
	switch (g_GamePhase)
	{
		//Begin
	case eBegin:
	{
		//Process Game Begin
		procPlayBegin();
		//switch to Main
		g_GamePhase = eMain;
	}
	break;

	//Main
	case eMain:
	{
		//Process Main
		procPlayMain();

		//g_GamePhase = eEnd;
	}
	break;

	//Ending
	case eEnd:
	{
		//Game Ending
		procPlayEnd();

		//reset GamePhase
		g_GamePhase = eBegin;
	}
	break;
	}
}

void COriginalGameApp::procPlayBegin()
{
	g_pPlayer = new CPlayer;
}


void COriginalGameApp::procPlayMain()
{

}

void COriginalGameApp::procPlayEnd()
{
}
