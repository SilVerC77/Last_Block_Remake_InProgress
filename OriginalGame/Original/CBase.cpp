#include "CBase.h"
#include "CPicture.h"

CBase::CBase()
	:m_pBody(nullptr)
	, m_pHitBox(nullptr)
	, m_Pos(0.f, 0.f)
	, m_Size(0.f, 0.f)
	, m_fHP(1.f)
{

}

CBase::~CBase()
{
	if (m_pBody) m_pBody->release();
	if (m_pHitBox)m_pHitBox->release();
}

void CBase::BeginPlay()
{

}

void CBase::Tick(const float& _DeltaTime)
{
}

void CBase::TakeDamage(const float& _Damage)
{

}

void CBase::AddMovement(const XMFLOAT2& _dir, const float& _vel)
{
	float mag = sqrt(_dir.x * _dir.x + _dir.y * _dir.y);
	if (fabsf(mag) < FLT_EPSILON)return;
	XMFLOAT2 vect(_dir / mag);
	XMFLOAT2 pos = m_Pos;
	pos += (vect * _vel);
	SetPos(pos);
}

void CBase::SetPos(const XMFLOAT2& _pos)
{
	m_Pos = _pos;
	if (m_pBody)m_pBody->setPos(_pos);
	if (m_pHitBox)m_pHitBox->setPos(_pos);
}
