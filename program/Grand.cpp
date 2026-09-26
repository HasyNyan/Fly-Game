#include "Grand.h"

void Grand::Init()
{
	m_Pos = VGet(0.0f, 0.0f, 0.0f);  //位置の初期化
	m_Scale = VGet(100.0f, 100.0f, 100.0f);//大きさの初期化
	m_model_Handle = MV1LoadModel("Asset/Model/Grand/ground.mv1");

	//モデルに位置と拡大率を反映させる
	MV1SetPosition(m_model_Handle, m_Pos);
	MV1SetScale(m_model_Handle, m_Scale);
}
void Grand::Update()
{

}
void Grand::Draw()
{
	for (int i = 0; i < GROUND_COUNT; ++i)
	{
		//iの数だけずらした位置を計算
		//プレイヤーの初期位置から手前～奥へ並べるイメージ
		VECTOR pos = VGet(0.0f, 0.0f, i * GROUND_LENGTH);

		MV1SetPosition(m_model_Handle, pos);
		MV1DrawModel(m_model_Handle);
	}
	
}
void Grand::Exit()
{
	MV1DeleteModel(m_model_Handle);
}