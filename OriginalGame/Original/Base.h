/**
* @file CPicture.h
* @brief テクセル付きのピクチャー・・クラス
* @author 織戸　喜隆
* @date 日付（2017.02.14）
*/
#pragma once
#include "stdafx.h"

/*! @class CPicture
@brief  ポリゴン・クラス
*/
class Base
{
	class CPicture* m_pBody;
	CPicture* m_pHitBox;
	XMFLOAT2 m_Pos;
	XMFLOAT2 m_Size;
public:
	Base();					//コンストラクタ
	virtual ~Base();		//デストラクタ

	/********************************
	* Method:Public
	*********************************/
	virtual void BeginPlay();
	virtual void Tick(const float _DeltaTime);

private:
	/********************************
	* Method:Private
	*********************************/

protected:
public:
	/********************************
	* Getter:Public
	*********************************/
	CPicture* GetBody()const { return m_pBody; }
	CPicture* GetHitBox()const { return m_pHitBox; }
	XMFLOAT2 GetPos()const { return m_Pos; }
	XMFLOAT2 GetSize()const { return m_Size; }
};

