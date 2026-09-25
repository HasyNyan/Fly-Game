#include "ResultScene.h"

ResultScene::ResultScene(){}
ResultScene::~ResultScene(){}

void ResultScene::Init()
{
	m_RankingManager.Init();//ファイルから過去のランキングをロード
	m_RankingManager.AddScore(m_CurrentScore);//ファイルの上書き保存
}

SceneType ResultScene::Update()
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		return SceneType::TITLE;
	}
	return SceneType::RESULT;
}

void ResultScene::Draw()
{	
	// 今回獲得したスコア（飛距離）を画面に大きく表示
	DrawFormatString(300, 150, GetColor(255, 255, 255), "YOUR SCORE: %.2fm", m_CurrentScore);

	//ランキングの描画
	m_RankingManager.Draw();

	//ランキングなどのテキスト描画
	DrawString(300, 250, "===RESULT SCREEN===", GetColor(255, 255, 255));
	DrawString(280, 300, "Press [R] to Return Title", GetColor(255, 255, 255));
}