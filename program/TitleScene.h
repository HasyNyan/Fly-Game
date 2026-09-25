#pragma once
#include "Iscene.h"

class TitleScene : public IScene
{
public:
	TitleScene();
	virtual ~TitleScene() override;

	virtual void Init() override;
	virtual SceneType Update() override;
	virtual void Draw() override;
};