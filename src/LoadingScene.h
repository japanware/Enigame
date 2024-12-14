//
// Created by KOZY on 12/4/2024.
//

#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "Scene.h"
#include "AssetManager.h"

class LoadingScene : public Scene {
private:
  Utils utils;

  TextEx m_loadingText;
  TextureEx m_logo;
  int m_textMeasurement;

public:
  LoadingScene();
  ~LoadingScene() override;

  void update(float deltaTime) override;
  void render(Renderer &renderer) override;
  void onEnter() override;
  void onExit() override;
};



#endif //LOADINGSCENE_H
