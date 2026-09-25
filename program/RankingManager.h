#pragma once
#include<vector>
#include<algorithm>

class RankingManager
{
private:
	//ランキングのデータを格納する配列
	std::vector<float>m_Rankings;
	const int  MAX_RANKING = 3;

	void Load();//ファイルから読み込む処理
	void Save();//ファイルへの書き込む処理

public:
	RankingManager();
	void Init();//最初に保存されたデータを読み込むなど

	//新しい記録をチェックして、ランキング圏内なら追加して並び変える関数
	void AddScore(float newScore);

	//ランキング画面(1位～3位)を描画する関数
	void Draw();
};