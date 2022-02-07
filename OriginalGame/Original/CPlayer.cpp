#include "CPlayer.h"

CPlayer::CPlayer()
	:m_fSpeed(1000.f)
	, m_Vel(0.f, 0.f)
	, m_InputVel(0.f, 0.f)
	, m_bIsJump(false)
	, m_fJumpHeight(100.f)
	, m_fJumpDur(4.f)
{
	m_fJumpInitVel = 2.f * m_fJumpHeight / m_fJumpDur;
	m_fGravity = 2.f * m_fJumpHeight / (m_fJumpDur * m_fJumpDur);
}

CPlayer::~CPlayer()
{
}

void CPlayer::BeginPlay()
{
	super::BeginPlay();

}

void CPlayer::Tick(const float& _DeltaTime)
{
	super::Tick(_DeltaTime);

	UpdateMove(_DeltaTime);
}

void CPlayer::TakeDamage(const float& _Damage)
{
	if (_Damage > 0.f)
		m_fHP -= _Damage;
}

void CPlayer::UpdateMove(const float& _DeltaTime)
{
	//float!=0.f ->	
	if (fabsf(m_InputVel.x) > FLT_EPSILON) {
		XMFLOAT2 dir(m_InputVel.x, 0.f);
		AddMovement(dir, m_fSpeed * _DeltaTime);
	}

	m_Vel.y -= m_fGravity * _DeltaTime;
	//if (m_Vel.y < 0.f)m_Vel.y = 0.f;
	AddMovement(XMFLOAT2(0.f, 1.f), m_Vel.y);
}

void CPlayer::MoveRight(const BOOL& _left, const BOOL& _right)
{
	if (_left) m_InputVel.x = -1.f;
	else if (_right) m_InputVel.x = 1.f;
	else m_InputVel.x = 0.f;
}

void CPlayer::Jump(const BOOL& _press)
{
	//if (_press)m_bIsJump = true;
	if (_press)m_Vel.y = m_fJumpInitVel;

	/*
	curHeight=.5f * decel * t * t + InitVel * t
	decel=-2.f * Max / (Dur* Dur)
	InitVel=2.f * Max / Dur
	*/
	/*http://openarena.ws/board/index.php?topic=5100.0
	temp = acc*dt
	pos = pos + dt*(vel + temp/2)
	vel = vel + temp
	*/
}
