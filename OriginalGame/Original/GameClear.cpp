#include "COriginalGameApp.h"
#include "GameResource.h"
#define PI 3.14

//変数定義-----------------------------------------------------------------------
//クリア画面のフェーズを管理する変数
ePhase g_ClearPhase = eBegin;

//クリア画面から次へ進むときのフローを管理する変数
eGameStatus g_NextStatusFromClear = eNone;

/*
 * ゲームクリア画面の処理を行う部分
 */
void COriginalGameApp::procClear(const float& _dt)
{
	//フェーズの進行状態によって処理を切り替える
	switch (g_ClearPhase)
	{
		//開始時
	case eBegin:
	{
		//クリア画面の開始処理を行う
		procClearBegin();
		//進行状態のメインに切り替える
		g_ClearPhase = eMain;
	}
	break;
	//メイン
	case eMain:
	{
		//クリア画面のメイン処理
		procClearMain();
	}
	break;
	//終了時
	case eEnd:
	{
		//クリア画面の終了処理を行う
		procClearEnd();
		//再度クリア画面に来た時に開始から処理を行うためにフェーズを戻しておく
		g_ClearPhase = eBegin;
		//次のステータスを設定する
		SetNextGameStatus(g_NextStatusFromClear);
	}
	break;
	}
}


/*
 * 関数名　：procClearBegin()
 * 処理内容　：クリア画面の開始時に行う処理
 * 引数　　　：なし
 * 戻り値　　：なし
 */
void COriginalGameApp::procClearBegin()
{
	
}

/*
 * 関数名　　：procClearMain()
 * 処理内容　：クリア画面のメイン処理
 *	引数　　　：なし
 *	戻り値　　：なし
 */
void COriginalGameApp::procClearMain()
{
	
}
/*
* 関数名　　：procClearEnd()
* 処理内容　：クリア画面の終了時に行う処理
* 引数　　　：なし
* 戻り値　　：なし
*/
void COriginalGameApp::procClearEnd()
{
	
}
