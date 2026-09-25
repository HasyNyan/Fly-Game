#pragma once
// 前方宣言（BulletManager.hをインクルードする代わりに「そういうクラスがあるよ」と伝える）
class BulletManager;

class Player
{
private:
    VECTOR m_Position = VGet(0.0f, 0.0f, 0.0f); // プレイヤーの座標

public:
    Player();
    void Init();
    // 弾の管理者を引数で受け取る
    void Update(BulletManager& bulletManager);
    void Draw();
    void Reset();
    VECTOR GetPosition() const { return m_Position;}
};