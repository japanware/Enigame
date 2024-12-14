//
// Created by KOZY on 11/26/2024.
//

#ifndef INTROSCENE_H
#define INTROSCENE_H

#include "Scene.h"
#include "raylib.h"


class IntroScene : public Scene {
private:
  std::shared_ptr<AssetManager> data;

  TextEx m_LogoText;
  TransformEx m_LogoTransform{};
  std::string m_LogoName;
  Texture2D m_LogoTexture;

public:
  IntroScene(const std::shared_ptr<AssetManager>& assetManager);
  ~IntroScene() override;

  void update(float deltaTime) override;
  void render(Renderer &renderer) override;
  void onEnter() override;
  void onExit() override;

};



#endif //INTROSCENE_H