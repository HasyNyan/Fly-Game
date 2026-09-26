#pragma once
class Grand
{
private:
	VECTOR m_Pos   = VGet(0.0f,0.0f,0.0f);
	VECTOR m_Scale = VGet(1.0f, 1.0f, 1.0f);
	int m_model_Handle = 0;

	const float GROUND_LENGTH = 100.0f;
	
	const int GROUND_COUNT = 10;

public:
	void Init();
	void Update();
	void Draw();
	void Exit();
};