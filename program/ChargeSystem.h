#pragma once
enum class ChargeState
{
	Waiting,	//キー入力待ち(ゲーム開始時)
	Charging,	//ゲージが自動で動いている状態
	Finished	//目押し完了(判定確定)
};

enum class ChargeResult
{
	None,		//チャージ中
	Just,		//ジャストタイミング
	Good,		//通常成功
	Overcharge	//溜めすぎ不発
};

class ChargeSystem
{
private:
	float m_currentCharge = 0.0f;
	float m_chargeSpeed = 0.8f;	//1秒間に溜まる速度
	//ジャスト範囲
	float m_justRangeMin = 0.8f;
	float m_justRangeMax = 0.9f;

	//ループ回数上限
	int m_loopCount = 0;
	const int MAX_LOOPS = 3;

	ChargeState m_state = ChargeState::Waiting;
	ChargeResult m_result = ChargeResult::None;
public:
	void Reset(); //ラウンド開始時などの初期化
	void Update(bool isSpacePressed,bool isAnyKeyPressed);//ボタンの長押し処理やチャージ量の更新

	float GetChargeRatio()   const { return m_currentCharge;}//0.0f～1.0f
	float GetJustRangeMin()  const { return m_justRangeMin;}//80%の位置
	float GetJustRangeMax()  const { return m_justRangeMax;}//90%の位置
	ChargeState  GetState()  const { return m_state;}
	ChargeResult GetResult() const { return m_result;}

};