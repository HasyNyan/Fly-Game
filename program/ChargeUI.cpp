#include "ChargeUI.h"


void ChargeUI::Draw(const ChargeSystem& chargeSystem)
{
	//カラーコードの取得(白,灰色,緑,赤,黄)
	unsigned int colorWhite  = GetColor(255, 255, 255);
	unsigned int colorGray   = GetColor(100, 100, 100);
	unsigned int colorGreen  = GetColor(  0, 255, 128);//ジャストゾーン(緑)
	unsigned int colorRed    = GetColor(255,  50,  50);//チャージゲージ(赤)
	unsigned int colorYellow = GetColor(255, 255,   0);//結果表示
}