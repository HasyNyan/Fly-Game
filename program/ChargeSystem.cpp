#include "ChargeSystem.h"
void ChargeSystem::Reset()
{
	m_currentCharge = 0.0f;
	m_loopCount = 0;
	m_state = ChargeState::Waiting;
	m_result = ChargeResult::None;
}

void ChargeSystem::Update(bool isSpacePressed,bool isAnyKeyPressed)
{
	switch(m_state)
	{
	case ChargeState::Waiting://開始待ち
			if (isAnyKeyPressed)
			{
				m_state = ChargeState::Charging;
				m_currentCharge = 0.0f;
				m_loopCount = 0;
			}
			break;
	case ChargeState::Charging://チャージ中
			//自動でゲージを増やす
			m_currentCharge += m_chargeSpeed * (1.0f / 60.0f);
			//最大を超えたら最初に戻す
			if (m_currentCharge >= 1.0f)
			{
				m_currentCharge = 0.0f;
				m_loopCount++;
				//3回チャージを見送ったら不発
				if (m_loopCount >= MAX_LOOPS)
				{
					m_result = ChargeResult::Overcharge;
					m_state  = ChargeState::Finished;
					break;
				}
			}
			if (isSpacePressed)
			{
				m_state = ChargeState::Finished;

				if (m_currentCharge >= m_justRangeMin && m_currentCharge <= m_justRangeMax)
				{
					m_result = ChargeResult::Just;//ジャスト成功
				}
				else
				{
					m_result = ChargeResult::Good;//通常成功
				}
			}
			break;
		case ChargeState::Finished:
			//判定終了後はなにもしない
			break;
	}
}