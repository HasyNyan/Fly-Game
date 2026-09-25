#pragma once
#include "IScene.h"

//前方宣言
class Player;
class BulletManager;
class Camera;
class Enemy;
class ScoreManager;
class Grand;

class GameScene : public IScene
{
private:

    std::unique_ptr<Player>         m_Player;
    std::unique_ptr<BulletManager>  m_BulletManager;
    std::unique_ptr<Camera>         m_Camera;
    std::unique_ptr<Enemy>          m_Enemy;
    std::unique_ptr<ScoreManager>   m_ScoreManager;
    std::unique_ptr<Grand>          m_Grand;

    void UpdateCollisions();
    void UpdateCamera();
    void UpdateScore();
    void ResetRoundPosition();//ラウンド変更にあたり他のオブジェクトたちを初期値に戻す関数

    int m_CurrentRound = 1;     //現在のラウンド
    const int MAX_ROUNDS = 3;   //最大ラウンド数
    float m_TotalScore = 0.0f;  //3回の合計スコア

    float m_FinalScore = 0.0f;//確定した最終スコア
public:
    GameScene();
    virtual ~GameScene() override;

    virtual void Init() override;
    virtual SceneType Update() override;
    virtual void Draw() override;

    //確定した最終スコアを取得するゲッター
    virtual float GetScore() const override { return m_FinalScore;}
};