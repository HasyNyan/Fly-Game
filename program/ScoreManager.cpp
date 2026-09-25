#include "ScoreManager.h"

ScoreManager::ScoreManager(){}

void ScoreManager::Init()
{
	m_CurrentDistance = 0.0f;
	m_IsTracking      = false;
}

void ScoreManager::StartTracking(VECTOR enemyPos)
{
	m_StartPosition = enemyPos; //飛んだ瞬間の位置を保存
	m_IsTracking    = true;     //計測のフラグをON
}

void ScoreManager::Update(VECTOR enemyPos)
{
	//計測中じゃなければ抜ける
	if (!m_IsTracking)return;

	//初期位置と現在の位置の「3次元的な直線距離」を計算する
	float rawDistance = VSize(VSub(enemyPos, m_StartPosition));

	//そのままだと数字が大きすぎるので、10分の1にして「メートル」っぽくする
	m_CurrentDistance = rawDistance * 0.1f;
}

void ScoreManager::Draw()
{
	DrawFormatString(20, 20, GetColor(255, 255, 255), "Distance: %.2fm", m_CurrentDistance);
}

void ScoreManager::Reset()
{
	m_CurrentDistance = 0.0f;
	m_IsTracking = false;
}

void ScoreManager::StopTracking() 
{
	//追跡フラグを「計測終了」にする
	m_IsTracking = false;
	//追跡終了フラグを終了にする
	m_IsFinished = true;
}