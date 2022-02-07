#include "CPlayer.h"

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
		AddMovement(m_InputVel, 2000.f * _DeltaTime);
	}

}

void CPlayer::MoveRight(const BOOL& _left, const BOOL& _right)
{
	if (_left) m_InputVel.x = -1.f;
	else if (_right) m_InputVel.x = 1.f;
	else m_InputVel.x = 0.f;
}

void CPlayer::Jump(const BOOL& _press)
{
	if (_press)m_InputVel.y = 1.f;
	else m_InputVel.y = 0.f;

}
