#pragma once
class Camera
{
private:
    VECTOR m_Position = VGet(0.0f,0.0f,0.0f); // カメラの位置
    VECTOR m_Target   = VGet(0.0f,0.0f,0.0f);   // カメラが見つめる位置

public:
    Camera();
    void Init();
    // 追跡するために、プレイヤーの座標を引数でもらう
    void Update(VECTOR targetPos, bool targetIsEnemy);
    void Reset();
};