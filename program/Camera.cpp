#include "Camera.h"

Camera::Camera() {}

void Camera::Init()
{
    // カメラの描画範囲を設定（ゲーム開始時に1回呼べばOK）
    SetCameraNearFar(1.0f, 2000.0f);
}

void Camera::Update(VECTOR targetPos,bool targetIsEnemy)
{
    // カメラが見つめる場所を「プレイヤーの座標」にする
    m_Target = VAdd(targetPos, VGet(0.0f, 10.0f, 0.0f));
    if (targetIsEnemy)
    {
        //飛んでいるときは,カメラはエネミーを見る
        m_Position = VAdd(targetPos, VGet(-50.0f, 30.0f, -120.0f));
    }
    else
    {
        //エネミーが飛んでいないときはカメラはプレイヤーを見る
        m_Position = VAdd(targetPos, VGet(0.0f, 40.0f, -80.0f));
    }
    //DXライブラリのカメラに、計算した座標をセットする
    SetCameraPositionAndTargetAndUpVec(m_Position, m_Target, VGet(0.0f, 1.0f, 0.0f));
}

void Camera::Reset()
{
    VECTOR m_Position = VGet(0.0f, 0.0f, 0.0f); // カメラの位置
    VECTOR m_Target = VGet(0.0f, 0.0f, 0.0f);   // カメラが見つめる位置
}