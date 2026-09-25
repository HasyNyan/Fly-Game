#include "Grand.h"

void Grand::Init()
{
	m_Pos = VGet(0.0f, 0.0f, 0.0f);  //ˆÊ’u‚Ì‰Šú‰»
	m_Scale = VGet(1000.0f, 1000.0f, 1000.0f);//‘å‚«‚³‚Ì‰Šú‰»
	m_model_Handle = MV1LoadModel("Asset/Model/Grand/ground.mv1");

	//ƒ‚ƒfƒ‹‚ÉˆÊ’u‚ÆŠg‘å—¦‚ğ”½‰f‚³‚¹‚é
	MV1SetPosition(m_model_Handle, m_Pos);
	MV1SetScale(m_model_Handle, m_Scale);
}
void Grand::Update()
{

}
void Grand::Draw()
{
	MV1DrawModel(m_model_Handle);
}
void Grand::Exit()
{
	MV1DeleteModel(m_model_Handle);
}