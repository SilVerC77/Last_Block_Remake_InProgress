#include "CBase.h"
#include "CPicture.h"

CBase::CBase()
	:m_pBody(nullptr)
	, m_pHitBox(nullptr)
	, m_Pos(0.f, 0.f)
	, m_Size(0.f, 0.f)
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
