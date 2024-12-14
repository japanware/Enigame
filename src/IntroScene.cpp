//
// Created by KOZY on 11/26/2024.
//

#include "IntroScene.h"

// TODO: Make this fucking shit work. I am questioning my skills when it comes to this architecture
// Not sure if I should pass a shared_ptr as a parameter here or make a seperate shared pointer
// pointer to this crap for ownership OR even fucking implement a singleton, but then I might make it
// a unique_ptr
IntroScene::IntroScene(const std::shared_ptr<AssetManager>& assetManager) : data(assetManager) {
  m_LogoText.position.x = GetScreenWidth() / 2;
  m_LogoText.position.y = (GetScreenHeight() / 2);
  m_LogoText.text = "CUM ENGINE 0.1b";
  m_LogoText.fontSize = 20;

  m_LogoName = "cookie.png";
  m_LogoText.position.x = (GetScreenWidth() / 2) - assetManager->getTextureWidth(m_LogoName);

  // TODO: Initialize texture to test
}

IntroScene::~IntroScene() {}

void IntroScene::onEnter() {

}

void IntroScene::onExit() {}

void IntroScene::update(float deltaTime) {

}

void IntroScene::render(Renderer &renderer) {
  DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

  renderer.renderTexture(
      m_LogoName,
      m_LogoTransform
  );

}