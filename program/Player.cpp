#include "Player.h"
#include "Main.h"
#include "BulletManager.h" // 処理を動かすためにここでインクルードする

Player::Player(){}

void Player::Init()
{
    m_Position = VGet(0.0f, 0.0f, 0.0f); // 初期位置
}

void Player::Update(BulletManager& bulletManager)
{
    //プレイヤー自体の移動処理
    if (CheckHitKey(KEY_INPUT_UP))    m_Position.z += 1.0f;
    if (CheckHitKey(KEY_INPUT_DOWN))  m_Position.z -= 1.0f;

    // 弾の発射処理
    // スペースキーが「今押された瞬間」なら弾を撃つ
    if (PushHitKey(KEY_INPUT_SPACE))
    {
        // プレイヤーの目の前（今回はZ軸のプラス方向）に向けて飛ばす
        VECTOR targetPos = VAdd(m_Position, VGet(0.0f, 0.0f, 100.0f));
        float speed = 5.0f;

        // 司令塔から受け取ったマネージャーに発射を依頼！
        bulletManager.Shot(m_Position, targetPos, speed);
    }
}

void Player::Draw()
{
    float size = 10.0f; // キューブの大きさ（半径のようなもの）

    // 中心座標から、全軸マイナスした点（左下奥）と、全軸プラスした点（右上手前）を作る
    VECTOR minPos = VSub(m_Position, VGet(size, size, size));
    VECTOR maxPos = VAdd(m_Position, VGet(size, size, size));
    // プレイヤーの見た目（例として黄色い立方体）
    DrawCube3D(minPos, maxPos, GetColor(255, 255, 0), GetColor(255, 255, 0), TRUE);
}

void Player::Reset()
{
    m_Position = VGet(0.0f, 0.0f, 0.0f);
}