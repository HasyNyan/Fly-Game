#pragma once
class Enemy
{
private:
	VECTOR m_Position = VGet(0.0f, 0.0f, 0.0f);
	VECTOR m_Velocity = VGet(0.0f, 0.0f, 0.0f);

	float m_ChargedPower = 0.0f;
	int   m_ChargeTimer  = 0;
	bool  m_IsFlying     = false;
	float m_Scale        = 0.0f;
public:
	Enemy();
	void Init();
	void Update();
	void Draw();
	void Reset();

	//外部からパワーを溜めさせるための関数
	void AddPower(float power);

	//当たり判定ように、エネミーの現在の座標を外に教える関数
	VECTOR GetPosition() const { return m_Position; }
	//外部から大きさを取得させるための関数
	float GetScale() const { return m_Scale; }
	//飛んでいる状態かどうかを外部に伝える関数
	bool IsFlying() const { return m_IsFlying; }
};