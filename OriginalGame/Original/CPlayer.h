#pragma once
#include "CBase.h"

class CPlayer :
	public CBase
{
	XMFLOAT2 m_InputVel;
private:
	void UpdateMove(const float& _DeltaTime);
public:
	virtual void BeginPlay()override;
	virtual void Tick(const float& _DeltaTime)override;
	virtual void TakeDamage(const float& _Damage)override;

	void MoveRight(const BOOL _left,const BOOL _right);
};

