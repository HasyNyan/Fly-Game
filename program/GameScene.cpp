#include "GameScene.h"
#include "Grand.h"
#include "Player.h"
#include "BulletManager.h"
#include "Camera.h"
#include "Enemy.h"
#include "ScoreManager.h"
//コンストラクタ
GameScene::GameScene(){}
//デストラクタ
GameScene::~GameScene(){}

void GameScene::Init()
{
	m_Grand			= std::make_unique<Grand>();
	m_Player        = std::make_unique<Player>();
	m_BulletManager = std::make_unique<BulletManager>();
	m_Camera		= std::make_unique<Camera>();
	m_Enemy			= std::make_unique<Enemy>();
	m_ScoreManager  = std::make_unique<ScoreManager>();

	m_Grand		  ->Init();
    m_Player      -> Init();
    m_Camera      -> Init();
    m_Enemy       -> Init();
    m_ScoreManager-> Init();
}

SceneType GameScene::Update()
{
    m_Player       -> Update(*m_BulletManager);
    m_BulletManager-> Update();
    m_Enemy        -> Update();

    UpdateCollisions();
    UpdateCamera();

	//シーン遷移判定を先に行う
	bool isFinishedFlight = (m_ScoreManager->IsTracking() && !m_Enemy->IsFlying());
	//スコアの更新とStopTrackingを行う
    UpdateScore();
	//判定結果に基づいてRESULTシーンへ遷移要求を出す
	if (isFinishedFlight)
	{	//今回のスコアを累計に加算
		m_TotalScore += m_ScoreManager->GetCurrentDistance();
		//ラウンド数がMAX_ROUNDSより下だったら
		if (m_CurrentRound < MAX_ROUNDS)
		{
			//ラウンドカウントを加算する
			m_CurrentRound++;
			//メーターの速度を上げる
			//m_ChargeMeter->SetSpeedRate(1.0f + (m_CurrentRound * 0.5f));
			//ステージを切り替える
			//m_Grand->ChangeStage(m_CurrentRound);
			//プレイヤー,エネミー、カメラ,スコア追跡を初期値にリセット
			ResetRoundPosition();
		}
		else
		{
			m_FinalScore = m_TotalScore;//3回の合計値などを最終スコアにする
			return SceneType::RESULT;	//最終スコアが確定したらResultSceneへ
		}
	}
    // 画面を維持する場合は自分自身のシーンタイプを返す
    return SceneType::GAME;
}

void GameScene::Draw()
{
	m_Grand ->Draw();
	m_Player->Draw();
	m_BulletManager->Draw();
	m_Enemy->Draw();
	//現在の飛距離メーターを描画
	m_ScoreManager->Draw();

}

//当たり判定の処理をする関数
void GameScene::UpdateCollisions()
{
	for (int i = 0; i < m_BulletManager -> GetMaxBullets(); i++)
	{
		if (!m_BulletManager -> GetBulletActive(i)) continue;
		VECTOR bPos = m_BulletManager -> GetBulletPosition(i);
		VECTOR ePos = m_Enemy -> GetPosition();
		float hitRadius = 5.0f + (15.0f * m_Enemy -> GetScale());

		if (VSize(VSub(bPos, ePos)) < hitRadius)
		{
			m_BulletManager->KillBullet(i);
			m_Enemy->AddPower(5.0f);
		}
	}
}

//カメラの操作をする関数
void GameScene::UpdateCamera()
{
	//エネミーが飛んでいるかどうかで見る座標を替える
	if (m_Enemy -> IsFlying())
	{
		//飛んだ状態になったらエネミーの座標を渡す
		m_Camera -> Update(m_Enemy->GetPosition(), true);
	}
	else
	{
		m_Camera -> Update(m_Player->GetPosition(), false);
	}
}
//飛距離の計測と処理をする関数
void GameScene::UpdateScore()
{
	//エネミーが飛んだ瞬間に計測を開始する
	//まだ計測が始まっていない状態かつエネミーが飛んでいる状態なら計測スタート
	if (m_Enemy -> IsFlying() && !m_ScoreManager -> IsTracking())
	{
		m_ScoreManager -> StartTracking(m_Enemy -> GetPosition());
	}

	//毎フレーム、エネミーの座標を渡して距離を計算させる
	m_ScoreManager -> Update(m_Enemy -> GetPosition());

	//飛び終わった瞬間
	if (m_ScoreManager->IsTracking() && !m_Enemy->IsFlying())
	{
		//最終スコアを保持し、追跡を停止する
		m_FinalScore = m_ScoreManager->GetCurrentDistance();
		//スコアマネージャーの追跡を止めて、何度もこの判定に入らないようにする
		m_ScoreManager->StopTracking();
	}

}

//ラウンド変更にあたり他のオブジェクトたちを初期値に戻す関数
void GameScene::ResetRoundPosition()
{
	m_Player->Reset();
	m_Enemy->Reset();
	m_BulletManager->Reset();
	m_ScoreManager->Reset();
	m_Camera->Reset();
}