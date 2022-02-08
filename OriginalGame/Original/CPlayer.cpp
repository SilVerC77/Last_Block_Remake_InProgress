#include "CPlayer.h"
#include "OutputDebugString.h"

CPlayer::CPlayer()
	:m_fSpeed(1000.f)
	, m_Vel(0.f, 0.f)
	, m_InputVel(0.f, 0.f)
	, m_bIsJump(false)
	, m_fJumpHeight(500.f)
	, m_fJumpDur(1.5f)
{
	float timetoMax = m_fJumpDur / 2.f;
	m_fGravity = 2.f * m_fJumpHeight / (timetoMax * timetoMax);
	m_fJumpInitVel = 2.f * m_fJumpHeight / timetoMax;
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

	//float mark = GetPos().y;

	m_Vel.y -= m_fGravity * _DeltaTime;
	float vel = m_Vel.y * _DeltaTime + (.5f * m_fGravity * _DeltaTime * _DeltaTime);
	AddMovement(XMFLOAT2(0.f, 1.f), vel);

	if (GetPos().y < -540.f)SetPos(XMFLOAT2(GetPos().x, -540.f));
	//if (GetPos().y > mark)
		//OutputDebugString(TEXT("new Height %f \n"), GetPos().y);
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
