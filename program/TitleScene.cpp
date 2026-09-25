#include "TitleScene.h"

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::Init()
{

}

SceneType TitleScene::Update()
{
	//スペースキーが押されたら、ゲームシーンに切り替える
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return SceneType::GAME;
	}     

	//何も押されていなければタイトル画面を維持
	return SceneType::TITLE;
}

void TitleScene::Draw()
{
	DrawString(300, 250,"===TITLE SCREEN===",GetColor(255, 255, 255));
	DrawString(280, 300, "Press[SPACE] to Start Game", GetColor(255, 255, 255));
}