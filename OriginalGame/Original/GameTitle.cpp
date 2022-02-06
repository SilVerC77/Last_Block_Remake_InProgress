#include "COriginalGameApp.h"
#include "GameResource.h"
#define PI 3.14


//変数定義-----------------------------------------------------------------------
//タイトル画面のフェーズを管理する変数
ePhase g_TitlePhase = eBegin;
//タイトルから次へ進むときのフローを管理する変数
eGameStatus g_NextStatusFromTitle = eNone;

/*
 * タイトルの処理を行う部分
 */
void COriginalGameApp::procTitle(const float& _dt)
{
	//フェーズの進行状態によって処理を切り替える
	switch (g_TitlePhase)
	{
		//開始時
	case eBegin:
	{
		//タイトル画面の開始時の処理を行う
		procTitleBegin();
		//進行状態のメインに切り替える
		g_TitlePhase = eMain;
	}
	break;
	//メイン
	case eMain:
	{
		//タイトル画面のメイン処理を行う
		procTitleMain();
		
		//g_TitlePhase = eEnd;
	}
	break;
	//終了時
	case eEnd:
	{
		//タイトル画面の終了処理を行う
		procTitleEnd();
		//再度タイトル画面に来た時に開始から処理を行うために
		//フェーズを戻しておく
		g_TitlePhase = eBegin;
		//次のステータスを設定する
		g_NextStatusFromTitle = ePlaying;
		SetNextGameStatus(g_NextStatusFromTitle);
	}
	break;
	}
}

/*
 * 関数名　：procTitleBegin()
 * 処理内容　：タイトル画面の開始時に行う処理
 * 引数　　　：なし
 * 戻り値　　：なし
 */
void COriginalGameApp::procTitleBegin()
{
	m_vpPicture.push_back(createSprite(Tex_Back, 1930.f, 1090.f));//Background

	/*if (!m_pBackground)
		m_pBackground = createSprite(Tex_Back, 1930.f, 1090.f);*/
}

/*
 * 関数名　　：procTitleMain()
 * 処理内容　：タイトル画面のメイン処理
 *	引数　　　：なし
 *	戻り値　　：なし
 */
void COriginalGameApp::procTitleMain()
{
	if (m_pDirectInput->isKeyPressed(DIK_X)) {
		g_TitlePhase = eEnd;
	}

	/**RENDER**/
	for (auto itr = m_vpPicture.begin(); itr != m_vpPicture.end(); ++itr)
		if (*itr) renderSprite(*itr);
}
/*
* 関数名　　：procTitleEnd()
* 処理内容　：タイトル画面の終了時に行う処理
* 引数　　　：なし
* 戻り値　　：なし
*/
void COriginalGameApp::procTitleEnd()
{
	for (auto itr = m_vpPicture.begin(); itr != m_vpPicture.end(); ++itr)
		if (*itr) disposeSprite(*itr);
	m_vpPicture.clear();
}