/**
* @file COriginalGameApp.h
* @author �D�ˁ@�엲
* @date ���t�i2017.02.14�j
*/
#pragma once

#include "stdafx.h"
#include "CApplication.h"
#include "CPicture.h"
#include "MediaResource.h"
#include "UVAnimation.h"
#include "CFont.h"
#include "CSound.h"

//#include "Original/CTimer.h"

class COriginalGameApp :
	public CApplication
{
	typedef CApplication super;
private:
	vector<CPicture*> m_vpPicture;
	CPicture* m_pBackground;

	CPicture* createSprite(LPCWSTR path_, float width_ = WINDOW_WIDTH, float height_ = WINDOW_HEIGHT);
	void renderSprite(CPicture* object);
	void renderSprite(CPicture* object, XMFLOAT3 color);
	void renderSprite(CPicture* object, XMFLOAT4 color);
	void disposeSprite(CPicture* object);
	CFont* createFont(LPCWSTR path_, int digits, float width = WINDOW_WIDTH, float height = WINDOW_HEIGHT);
	void renderFont(CFont* objects, int num_);
	void disposeFont(CFont* objects);
	bool createSpaceship(void);
	void initCameraInfo();
	void doOpenning(const float& _dt);
	void doPlaying(const float& _dt);
	void doGameClear(const float& _dt);
	void doGameOver(const float& _dt);
	void doEnding(const float& _dt);

	void procTitle(const float& _dt);
	void procGame(const float& _dt);
	void procClear(const float& _dt);
	void procGameOver(const float& _dt);

	void procTitleBegin();
	void procTitleMain();
	void procTitleEnd();
	void procPlayBegin();
	void procPlayMain();
	void procPlayEnd();
	void procClearBegin();
	void procClearMain();
	void procClearEnd();
	void procOverBegin();
	void procOverMain();
	void procOverEnd();

	CSound* createSound(const char* filePath_, const bool loop_ = false);
	void PlaySourceSound(CSound* const objects);
	void diseposeSound(CSound* const objects);

public:
	COriginalGameApp();
	~COriginalGameApp();
	void render(XMFLOAT4X4 matView, XMFLOAT4X4 matProj);
	void release();
};
