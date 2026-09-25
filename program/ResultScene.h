#pragma once
#include "IScene.h"
#include "RankingManager.h"
class ResultScene :public IScene
{
private:
	float m_CurrentScore = 0.0f;
	RankingManager m_RankingManager;
public:
	ResultScene();
	virtual ~ResultScene() override;

	virtual void Init() override;
	virtual SceneType Update() override;
	virtual void Draw() override;

	//SceneManagerからスコアを受け取るセッター関数
	virtual void SetScore(float score) { m_CurrentScore = score; }
};