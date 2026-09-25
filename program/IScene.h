#pragma once
//シーンの名前を定義
enum class SceneType
{
	TITLE,
	GAME,
	RESULT
};

//すべてのシーンが共通して持つべき「形」を決めるクラス
class IScene
{
public:
	virtual ~IScene(){}
	virtual void Init() = 0;
	virtual SceneType Update() = 0;//戻り値で「次のシーンを渡す」
	virtual void Draw() = 0;

	virtual float GetScore() const { return 0.0f; }
	virtual void  SetScore(float score){}
};