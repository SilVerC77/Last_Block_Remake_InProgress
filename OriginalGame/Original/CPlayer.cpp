#include "CPlayer.h"

void CPlayer::UpdateMove(const float& _DeltaTime)
{
}

void CPlayer::BeginPlay()
{
}

void CPlayer::Tick(const float& _DeltaTime)
{
}

void CPlayer::TakeDamage(const float& _Damage)
{
	if (_Damage > 0.f)
		m_fHP -= _Damage;
}

void CPlayer::MoveRight(const BOOL _left, const BOOL _right)
{
	if (_left) m_InputVel.x = -1.f;
	if (_right) m_InputVel.x = 1.f;
}
