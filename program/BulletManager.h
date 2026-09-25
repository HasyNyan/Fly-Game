#pragma once
#include "Bullet.h" // Bulletクラスを読み込む

class BulletManager
{
private:
    static const int MAX_BULLETS = 100;
    Bullet m_Bullets[MAX_BULLETS]; // Bulletクラスの配列

public:
    BulletManager();
    void Shot(VECTOR startPos, VECTOR targetPos, float speed);
    void Update();
    void Draw();
    void Reset();
    //外部から「i番目の弾」の座標やアクティブ状態を覗き見るための関数
    bool   GetBulletActive(int index) const { return m_Bullets[index].IsActive();}
    VECTOR GetBulletPosition(int index)const { return m_Bullets[index].GetPosition(); }
    void   KillBullet(int index) { m_Bullets[index].Kill();}//弾を消す用
    int    GetMaxBullets() const { return MAX_BULLETS;}
};