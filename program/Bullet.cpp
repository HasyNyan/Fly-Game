#include"Bullet.h";


Bullet::Bullet(){}

void Bullet::Init(VECTOR startPos, VECTOR targetPos, float speed)
{
    m_Active = true;
    m_Position = startPos;
    m_LifeTimer = 180;

    VECTOR dir = VSub(targetPos, startPos);
    m_Velocity = VScale(VNorm(dir), speed);
}

void Bullet::Update()
{
    if (!m_Active) return;

    // 移動処理
    m_Position = VAdd(m_Position, m_Velocity);

    // 寿命チェック
    m_LifeTimer--;
    if (m_LifeTimer <= 0) m_Active = false;
}

void Bullet::Draw()
{
    if (!m_Active) return;
    DrawSphere3D(m_Position, 5.0f, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
}