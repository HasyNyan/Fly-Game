#include "Enemy.h"

Enemy::Enemy() {};

void Enemy::Init()
{
	m_Position     = VGet(0.0f, 0.0f, 200.0f);
    m_Velocity     = VGet(0.0f, 0.0f, 0.0f);
    m_ChargedPower = 0.0f;
    m_ChargeTimer  = 0;
    m_IsFlying     = false;
    m_Scale        = 1.0f;
}

void Enemy::AddPower(float power)
{
    if (m_IsFlying) return; //すでに飛ばされている場合はチャージをしない;

    m_ChargedPower += power;//パワーを上乗せ
    m_ChargeTimer   = 120;  //タイマーを2秒(120フレーム)にセット(上書き)
    m_Scale        += 0.2f; //弾が当たるたびに、サイズを少しずつ大きくする
    //最大サイズを制限する
    if (m_Scale > 3.0f)
    {
        m_Scale = 3.0f;//3.0倍でストップさせる
    }
}

void Enemy::Update()
{
    //パワーを溜め込んでいる最中の処理(タイマーのカウントダウン)
    if (m_ChargeTimer > 0 && !m_IsFlying)
    {
        m_ChargeTimer--;

        //タイマーが0になった瞬間に、溜まったパワーを解放して飛ばす
        if (m_ChargeTimer == 0)
        {
            m_IsFlying = true;
            //真奥方向に、溜まったパワーの分だけ速度を与える
            m_Velocity = VGet(0.0f, 0.0f, m_ChargedPower);
        }
    }

    //飛んでいる最中の処理
    if (m_IsFlying)
    {
        //速度を座標に足して移動させる
        m_Position = VAdd(m_Position, m_Velocity);
        //空気抵抗などで徐々に減速させる
        m_Velocity = VScale(m_Velocity, 0.98f);
        //速度が小さくなったら
        if (VSize(m_Velocity) < 0.001f)
        {
            m_Velocity = VGet(0.0f, 0.0f, 0.0f); // 完全に止める
            m_IsFlying = false;                  // 飛行終了
        }
        //元のサイズより大きければ、少しずつ小さく
        if (m_Scale > 1.0f)
        {
            m_Scale -= 0.005f;//毎フレーム少しずつ小さく
            if (m_Scale < 1.0f)m_Scale = 1.0f;
        }
    }
}

void Enemy::Draw()
{
    //通常は赤,チャージ中は緑,飛んでいる最中は青に変化させる立方体
    unsigned int          color = GetColor(255, 0, 0);//赤
    if (m_ChargeTimer > 0)color = GetColor(0, 255, 0);//緑
    if (m_IsFlying)       color = GetColor(0, 0, 255);//青

    float baseSize = 15.0f;
    float currentSize = baseSize * m_Scale;//これでサイズが可変になる

    // 中心座標から、全軸マイナスした点（左下奥）と、全軸プラスした点（右上手前）を作る
    VECTOR minPos = VSub(m_Position, VGet(currentSize, currentSize, currentSize));
    VECTOR maxPos = VAdd(m_Position, VGet(currentSize, currentSize, currentSize));
    // プレイヤーの見た目（例として黄色い立方体）
    DrawCube3D(minPos, maxPos,color, color, TRUE);
}

void Enemy::Reset()
{
    m_Position = VGet(0.0f, 0.0f, 200.0f);
    m_Velocity = VGet(0.0f, 0.0f, 0.0f);
    m_ChargedPower = 0.0f;
    m_ChargeTimer = 0;
    m_IsFlying = false;
    m_Scale = 1.0f;
}