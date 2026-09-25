#include "GameScene.h"  
#include "TitleScene.h"
#include "ResultScene.h"
#include "SceneManager.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() { delete m_CurrentScene; }

void SceneManager::Init()
{
    // 最初はタイトル画面からスタート
    ChangeScene(SceneType::TITLE);
}

void SceneManager::Update()
{
    if (!m_CurrentScene) return;

    // 現在のシーンを更新し、次の要望（RESULTなど）を受け取る
    SceneType next = m_CurrentScene->Update();

    // もし現在のシーンが「別のシーンに行きたい！」と言ってきたら切り替える
    if (next != m_CurrentType)
    {
        float score = m_CurrentScene->GetScore();
       ChangeScene(next,score);
    }  
}

void SceneManager::Draw()
{
    if (m_CurrentScene) m_CurrentScene->Draw();
}

void SceneManager::ChangeScene(SceneType nextScene,float score)
{
    // 今のシーンを削除（お片付け）
    delete m_CurrentScene;
    m_CurrentScene = nullptr;

    // 指定された新しいシーンを作る
    switch (nextScene)
    {
    case SceneType::TITLE:  m_CurrentScene = new TitleScene();  break;
    case SceneType::GAME:   m_CurrentScene = new GameScene();   break;
    case SceneType::RESULT: m_CurrentScene = new ResultScene(); break;
    }

    m_CurrentType = nextScene;

    // 新しいシーンを初期化
    if (m_CurrentScene)
    {
        //作成されたシーンにスコアを流し込んでからInit()を呼ぶ
        m_CurrentScene->SetScore(score);
        m_CurrentScene->Init();
    }
}