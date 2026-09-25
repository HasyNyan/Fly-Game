#include "BulletManager.h"

BulletManager::BulletManager() {}

void BulletManager::Shot(VECTOR startPos, VECTOR targetPos, float speed)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        // 弾側の「使われていない」をチェック
        if (!m_Bullets[i].IsActive())
        {
            m_Bullets[i].Init(startPos, targetPos, speed);
            break;
        }
    }
}

void BulletManager::Update()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        m_Bullets[i].Update(); // 各弾のUpdateを呼ぶ
    }
}

void BulletManager::Draw()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        m_Bullets[i].Draw(); // 各弾のDrawを呼ぶ
    }
}

void BulletManager::Reset()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        m_Bullets[i].Kill();//配列内の全弾を強制的に非アクティブ化する
    }
}