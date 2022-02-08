#pragma once
#include "CBase.h"

class CPlayer : public CBase
{
	typedef CBase super;
	XMFLOAT2 m_InputVel;
	XMFLOAT2 m_Vel;
	float m_fSpeed;
	bool m_bIsJump;
	float m_fJumpHeight;
	float m_fJumpElap;		//elapsed time after jump
	float m_fJumpDur;		//half is to the peek of jump
	float m_fJumpInitVel;	//Initial Velocity of Jump
	float m_fGravity;
public:
	CPlayer();
	~CPlayer();
private:
	void UpdateMove(const float& _DeltaTime);
public:
	virtual void BeginPlay()override;
	virtual void Tick(const float& _DeltaTime)override;
	virtual void TakeDamage(const float& _Damage)override;

	void MoveRight(const BOOL& _left, const BOOL& _right);
	void Jump(const BOOL& _press);
};

