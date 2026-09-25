#pragma once
#include "IScene.h"

class SceneManager
{
private:
    IScene* m_CurrentScene  = nullptr; // 現在アクティブなシーン
    SceneType m_CurrentType = SceneType::TITLE;            // 現在のシーン名

    // シーンを新しく生成するヘルパー関数
    void ChangeScene(SceneType nextScene,float score = 0.0f);

public:
     SceneManager();
    ~SceneManager();

    void Init();
    void Update();
    void Draw();
};