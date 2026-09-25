#pragma once

class RankingManager;

class ScoreManager
{
private:
	float  m_CurrentDistance = 0.0f;                 //今の飛距離
	VECTOR m_StartPosition   = VGet(0.0f,0.0f,0.0f); //飛び始めた時のエネミーの座標
	bool   m_IsTracking      = false;                //飛距離を計算しているかどうか
	bool   m_IsFinished		 = false;				 //計測が終了したかどうか
public:
	ScoreManager();
	void Init();

	void StartTracking(VECTOR enemyPos);//飛んだ瞬間に計測を始める

	void Update(VECTOR enemyPos); //毎フレームエネミーの位置を見て距離を伸ばす

	void Reset();

	//外部から現在の飛距離を取得する関数
	float GetCurrentDistance() const { return m_CurrentDistance; }

	////完全にエネミーが止まったら、この関数の中でランキングマネージャーにデータを渡す
	//void FinalizeScore(RankingManager& rankingManager);

	void Draw();//現在の飛距離の画面表示

	//現在追跡中かどうか
	bool IsTracking() const { return m_IsTracking; };

	//追跡を終了させる関数
	void StopTracking();

	//計測が終了したかを返す関数
	bool IsFinished() const { return m_IsFinished; }
};