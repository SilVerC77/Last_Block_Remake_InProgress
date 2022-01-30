/**
 * ここでそれぞれの画像のUV座標を指定する
 */
#pragma once

#include "stdafx.h"
#include "Common3DType.h"

 // サンプル
const std::vector <QuadrangleTexel>   kTexelSamples = {
	//	左下					左上					右下					右上
	{ { 0.f / 4.f, 1.f }, { 0.f / 4.f, 0.f }, { 1.f / 4.f, 1.f }, { 1.f / 4.f, 0.f } },
};

//Player
const std::vector<QuadrangleTexel> kTexelPlayers = {
	//左下				左上	   		  右下				右上
	{{0.f / 1.f,1.f},{0.f / 1.f,0.f},{1.f / 1.f,1.f},{1.f / 1.f,0.f}}
};
const std::vector<QuadrangleTexel> kTexelPlayers_Move = {
	//左下				左上	   		  右下				右上
	{{0.f / 4.f,1.f},{0.f / 4.f,0.f},{1.f / 4.f,1.f},{1.f / 4.f,0.f}},		//0
	{ {1.f / 4.f,1.f},{1.f / 4.f,0.f},{2.f / 4.f,1.f},{2.f / 4.f,0.f}},		//1
	{ {2.f / 4.f,1.f},{2.f / 4.f,0.f},{3.f / 4.f,1.f},{3.f / 4.f,0.f}},		//2
	{ {3.f / 4.f,1.f},{3.f / 4.f,0.f},{4.f / 4.f,1.f},{4.f / 4.f,0.f}},		//3
};
const std::vector<QuadrangleTexel> kTexelPlayers_Die = {
	//左下				左上	   		  右下				右上
	{{0.f / 5.f,1.f},{0.f / 5.f,0.f},{1.f / 5.f,1.f},{1.f / 5.f,0.f}},		//0
	{ {1.f / 5.f,1.f},{1.f / 5.f,0.f},{2.f / 5.f,1.f},{2.f / 5.f,0.f}},		//1
	{ {2.f / 5.f,1.f},{2.f / 5.f,0.f},{3.f / 5.f,1.f},{3.f / 5.f,0.f}},		//2
	{ {3.f / 5.f,1.f},{3.f / 5.f,0.f},{4.f / 5.f,1.f},{4.f / 5.f,0.f}},		//3
	{ {4.f / 5.f,1.f},{4.f / 5.f,0.f},{5.f / 5.f,1.f},{5.f / 5.f,0.f}},		//4
};

const std::vector<QuadrangleTexel> kTexelEnemies_0 = {
	//左下				左上	   		  右下				右上
	{{0.f / 3.f,1.f},{0.f / 3.f,0.f},{3.f / 3.f,1.f},{3.f / 3.f,0.f}},
};
const std::vector<QuadrangleTexel> kTexelEnemies_0_Move = {
	//左下				左上	   		  右下				右上
	{{0.f / 3.f,1.f},{0.f / 3.f,0.f},{1.f / 3.f,1.f},{1.f / 3.f,0.f}},		//0
	{ {1.f / 3.f,1.f},{1.f / 3.f,0.f},{2.f / 3.f,1.f},{2.f / 3.f,0.f}},		//1
	{ {2.f / 3.f,1.f},{2.f / 3.f,0.f},{3.f / 3.f,1.f},{3.f / 3.f,0.f}},		//2
};
const std::vector<QuadrangleTexel> kTexelEnemies_1 = {
	//左下				左上	   		  右下				右上
	{{0.f / 3.f,1.f},{0.f / 3.f,0.f},{3.f / 3.f,1.f},{3.f / 3.f,0.f}},
};
const std::vector<QuadrangleTexel> kTexelEnemies_1_Move = {
	//左下				左上	   		  右下				右上
	{{0.f / 6.f,1.f},{0.f / 6.f,0.f},{1.f / 6.f,1.f},{1.f / 6.f,0.f}},		//0
	{ {1.f / 6.f,1.f},{1.f / 6.f,0.f},{2.f / 6.f,1.f},{2.f / 6.f,0.f}},		//1
	{ {2.f / 6.f,1.f},{2.f / 6.f,0.f},{3.f / 6.f,1.f},{3.f / 6.f,0.f}},		//2
	{ {3.f / 6.f,1.f},{3.f / 6.f,0.f},{4.f / 6.f,1.f},{4.f / 6.f,0.f}},		//3
	{ {4.f / 6.f,1.f},{4.f / 6.f,0.f},{5.f / 6.f,1.f},{5.f / 6.f,0.f}},		//4
	{ {5.f / 6.f,1.f},{5.f / 6.f,0.f},{6.f / 6.f,1.f},{6.f / 6.f,0.f}},		//5
};

const std::vector<QuadrangleTexel> kTexelEnemies_2 = {
	//左下				左上	   		  右下				右上
	{{0.f / 3.f,1.f},{0.f / 3.f,0.f},{3.f / 3.f,1.f},{3.f / 3.f,0.f}},
};
const std::vector<QuadrangleTexel> kTexelEnemies_2_Move = {
	//左下				左上	   		  右下				右上
	{{0.f / 4.f,1.f},{0.f / 4.f,0.f},{1.f / 4.f,1.f},{1.f / 4.f,0.f}},		//0
	{ {1.f / 4.f,1.f},{1.f / 4.f,0.f},{2.f / 4.f,1.f},{2.f / 4.f,0.f}},		//1
	{ {2.f / 4.f,1.f},{2.f / 4.f,0.f},{3.f / 4.f,1.f},{3.f / 4.f,0.f}},		//2
	{ {3.f / 4.f,1.f},{3.f / 4.f,0.f},{4.f / 4.f,1.f},{4.f / 4.f,0.f}},		//3
};


const std::vector<QuadrangleTexel> kTexelDie = {
	//左下				左上	   		  右下				右上
	{{0.f / 5.f,1.f},{0.f / 5.f,0.f},{1.f / 5.f,1.f},{1.f / 5.f,0.f}},// 1/5
	{{1.f / 5.f,1.f},{1.f / 5.f,0.f},{2.f / 5.f,1.f},{2.f / 5.f,0.f}},// 2/5
	{{2.f / 5.f,1.f},{2.f / 5.f,0.f},{3.f / 5.f,1.f},{3.f / 5.f,0.f}},// 3/5
	{{3.f / 5.f,1.f},{3.f / 5.f,0.f},{4.f / 5.f,1.f},{4.f / 5.f,0.f}},// 4/5
	{{4.f / 5.f,1.f},{4.f / 5.f,0.f},{5.f / 5.f,1.f},{5.f / 5.f,0.f}},// 5/5
};

//LOADING
const std::vector<QuadrangleTexel> kTexelLoading = {
	//左下				左上	   		  右下				右上
	{{0.f / 10.f,1.f},{0.f / 10.f,0.f},{1.f / 10.f,1.f},{1.f / 10.f,0.f}},// 1/10
	{{1.f / 10.f,1.f},{1.f / 10.f,0.f},{2.f / 10.f,1.f},{2.f / 10.f,0.f}},// 2/10
	{{2.f / 10.f,1.f},{2.f / 10.f,0.f},{3.f / 10.f,1.f},{3.f / 10.f,0.f}},// 3/10
	{{3.f / 10.f,1.f},{3.f / 10.f,0.f},{4.f / 10.f,1.f},{4.f / 10.f,0.f}},// 4/10
	{{4.f / 10.f,1.f},{4.f / 10.f,0.f},{5.f / 10.f,1.f},{5.f / 10.f,0.f}},// 5/10
	{{5.f / 10.f,1.f},{5.f / 10.f,0.f},{6.f / 10.f,1.f},{6.f / 10.f,0.f}},// 6/10
	{{6.f / 10.f,1.f},{6.f / 10.f,0.f},{7.f / 10.f,1.f},{7.f / 10.f,0.f}},// 7/10
	{{7.f / 10.f,1.f},{7.f / 10.f,0.f},{8.f / 10.f,1.f},{8.f / 10.f,0.f}},// 8/10
	{{8.f / 10.f,1.f},{8.f / 10.f,0.f},{9.f / 10.f,1.f},{9.f / 10.f,0.f}},// 9/10
	{{9.f / 10.f,1.f},{9.f / 10.f,0.f},{10.f / 10.f,1.f},{10.f / 10.f,0.f}},// 10/10
};

const std::vector<QuadrangleTexel> kTexelDifficulty = {
	//左下				左上	   		  右下				右上
	{{0.f / 2.f,1.f},{0.f / 2.f,0.f},{1.f / 2.f,1.f},{1.f / 2.f,0.f}}, // EASY
	{{1.f / 2.f,1.f},{1.f / 2.f,0.f},{2.f / 2.f,1.f},{2.f / 2.f,0.f}}, // HARD
};
const std::vector<QuadrangleTexel> kTexelEyelid = {
	//左下				左上	   		  右下				右上
	{{0.f / 6.f,1.f},{0.f / 6.f,0.f},{1.f / 6.f,1.f},{1.f / 6.f,0.f}},		//0
	{ {1.f / 6.f,1.f},{1.f / 6.f,0.f},{2.f / 6.f,1.f},{2.f / 6.f,0.f}},		//1
	{ {2.f / 6.f,1.f},{2.f / 6.f,0.f},{3.f / 6.f,1.f},{3.f / 6.f,0.f}},		//2
	{ {3.f / 6.f,1.f},{3.f / 6.f,0.f},{4.f / 6.f,1.f},{4.f / 6.f,0.f}},		//3
	{ {4.f / 6.f,1.f},{4.f / 6.f,0.f},{5.f / 6.f,1.f},{5.f / 6.f,0.f}},		//4
	{ {5.f / 6.f,1.f},{5.f / 6.f,0.f},{6.f / 6.f,1.f},{6.f / 6.f,0.f}},		//5
};
const std::vector<QuadrangleTexel> kTexelRate = {
	//左下				左上	   		  右下				右上
	{{0.f / 5.f,1.f},{0.f / 5.f,0.f},{1.f / 5.f,1.f},{1.f / 5.f,0.f}},		//0
	{ {1.f / 5.f,1.f},{1.f / 5.f,0.f},{2.f / 5.f,1.f},{2.f / 5.f,0.f}},		//1
	{ {2.f / 5.f,1.f},{2.f / 5.f,0.f},{3.f / 5.f,1.f},{3.f / 5.f,0.f}},		//2
	{ {3.f / 5.f,1.f},{3.f / 5.f,0.f},{4.f / 5.f,1.f},{4.f / 5.f,0.f}},		//3
	{ {4.f / 5.f,1.f},{4.f / 5.f,0.f},{5.f / 5.f,1.f},{5.f / 5.f,0.f}},		//4
};

//数字のUV座標
const std::vector<QuadrangleTexel> kTexelNumbers = {
	//左下		　左上		　右下		　右上
	{{0.8f,1.f},{0.8f,0.5f},{1.f,1.f},{1.f,0.5f}},//!<Number 0

	{{0.f,0.5f},{0.f,0.f},{0.2f,0.5f},{0.2f,0.f}},//!<Number 1
	{{0.2f,0.5f},{0.2f,0.f},{0.4f,0.5f},{0.4f,0.f}},//!<Number 2
	{{0.4f,0.5f},{0.4f,0.f},{0.6f,0.5f},{0.6f,0.f}},//!<Number 3
	{{0.6f,0.5f},{0.6f,0.f},{0.8f,0.5f},{0.8f,0.f}},//!<Number 4
	{{0.8f,0.5f},{0.8f,0.f},{1.f,0.5f},{1.f,0.f}},//!<Number 5

	{{0.f,1.f},{0.f,0.5f},{0.2f,1.f},{0.2f,0.5f}},//!<Number 6
	{{0.2f,1.f},{0.2f,0.5f},{0.4f,1.f},{0.4f,0.5f}},//!<Number 7
	{{0.4f,1.f},{0.4f,0.5f},{0.6f,1.f},{0.6f,0.5f}},//!<Number 8
	{{0.6f,1.f},{0.6f,0.5f},{0.8f,1.f},{0.8f,0.5f}},//!<Number 9
};