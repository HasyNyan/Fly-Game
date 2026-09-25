#include "RankingManager.h"
#include <fstream>

RankingManager::RankingManager(){}

void RankingManager::Init()
{
	m_Rankings.clear();
	Load();//ファイルからデータを読み込む
}
void RankingManager::AddScore(float newScore)
{
	//新しいスコアを配列の一番後ろに足す
	m_Rankings.push_back(newScore);
	//大きい順に(降順)に並び替える
	std::sort(m_Rankings.begin(), m_Rankings.end(), std::greater<float>());
	//もしMAX_RANKINGより多くデータがあったら、一番下のデータを消す
	if (m_Rankings.size() > MAX_RANKING)
	{
		m_Rankings.pop_back();
	}
	//データが更新されたので、ファイルに保存する
	Save();
}
//ロード処理の実装
void RankingManager::Load()
{
	//ファイルを読み込みモードで開く
	std::ifstream ifs("Ranking.dat");

	//もしファイルがまだ存在しない場合
	if(!ifs)
	{
		m_Rankings.push_back(0.0f);
		m_Rankings.push_back(0.0f);
		m_Rankings.push_back(0.0f);
		return;
	}
	//ファイルがある場合は,中身を1行ずつ読み込んで配列に入れる
	float score;
	while (ifs >> score)
	{
		m_Rankings.push_back(score);
	}
}
//セーブ処理の実装
void RankingManager::Save()
{
	//ファイルを書き込みモードで開く
	std::ofstream ofs("Ranking.dat");
	if (!ofs)return;//ファイルが開けなければreturn
	//配列の中身を1行ずつファイルに書き込む
	for (float score : m_Rankings)
	{
		ofs << score << "\n";
	}
}

void RankingManager::Draw()
{
	DrawString(400, 20, "=== RANKING ===", GetColor(255, 255, 255));
	for (size_t i = 0; i < m_Rankings.size(); i++)
	{
		//1位から順番に表示
		DrawFormatString(400, 50 + (i * 30), GetColor(255, 255, 0), "%d位: %.2fm", (int)i + 1, m_Rankings[i]);
	}
}