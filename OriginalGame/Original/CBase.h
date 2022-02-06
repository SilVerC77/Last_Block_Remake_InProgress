/**
* @file Base.h
* @brief
* @author 許弘毅
* @date 日付（2022.02.02）
*/
#pragma once
#include "stdafx.h"

/*! @class CBase
@brief
*/
class CBase
{
protected:
	class CPicture* m_pBody;
	CPicture* m_pHitBox;
	XMFLOAT2 m_Pos;
	XMFLOAT2 m_Size;
	float m_fHP;
public:
	CBase();					//コンストラクタ
	virtual ~CBase();		//デストラクタ

	/********************************
	* Method:Public
	*********************************/
	virtual void BeginPlay();
	virtual void Tick(const float& _DeltaTime);
	virtual void TakeDamage(const float& _Damage);
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

