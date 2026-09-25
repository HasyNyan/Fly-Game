#pragma once
class Bullet
{
private:
	bool	m_Active     = false;    //使用中か
	VECTOR  m_Position   = VGet(0.0f, 0.0f, 0.0f);  //座標
	VECTOR  m_Velocity   = VGet(0.0f, 0.0f, 0.0f);  //速度
	int		m_LifeTimer  = 0; //寿命
public:
	Bullet();
	void Init(VECTOR startPos, VECTOR targetPos, float speed);
	void Update();
	void Draw();

	//外部から状態を知るための関数(ゲッター)
	bool IsActive() const { return m_Active; }
	//外部から座標を取得するための関数
	VECTOR GetPosition() const { return m_Position;}
	void Kill() { m_Active = false; }//当たった時などに消す用
};