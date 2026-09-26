#pragma once
#include "ChargeSystem.h"

class ChargeUI
{
private:
	//メーターの描画位置・サイズに関する設定値
	float m_gaugeX = 200.0f;
	float m_gaugeY = 400.0f;
	float m_gaugeWidth = 400.0f;
	float m_gauseHeight = 30.0f;
public:
	//ChargeSystemの参照を受け取って画面にメーターを描画する
	void Draw(const ChargeSystem& chargeSystem);
};