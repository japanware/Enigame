//
// Created by KOZY on 12/4/2024.
//

#include "LoadingScene.h"

LoadingScene::LoadingScene() {
  // I needed to do initialize it like this, because initializer list won't work the way I thought
  // Might change it to initializer list when I find another way tho.

  // First initialize both of these because I need them for measurement
  m_loadingText.text = "Loading";
  m_loadingText.fontSize = 20;


  m_textMeasurement = MeasureText(m_loadingText.text.c_str(), m_loadingText.fontSize);

  m_loadingText.position.x = static_cast<float>((GetScreenWidth() / 2) - (m_textMeasurement / 2));
  m_loadingText.position.y = static_cast<float>(GetScreenHeight() - 200);
  m_loadingText.tint = WHITE;

  // Intitialize logo test
  m_logo.textureName = "Sprite-0002.png";
  AssetManager::getinstance()->loadAssetImage(m_logo.textureName);

  m_logo.textureFile = AssetManager::getinstance()->getTexture(m_logo.textureName);
  m_logo.transform.rotation = 0.0f;
  m_logo.transform.position.x = (GetScreenWidth() / 2) - (AssetManager::getinstance()->getTextureWidth(m_logo.textureName) / 2);
  m_logo.transform.position.y = (GetScreenHeight() / 2) - (AssetManager::getinstance()->getTextureHeight(m_logo.textureName) / 2);
}

void LoadingScene::update(float deltaTime) {
  m_logo.transform.rotation += 150.0f * deltaTime;
}

void LoadingScene::render(Renderer& renderer) {
  DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

  renderer.renderText(m_loadingText);
  renderer.renderTexture(m_logo.textureName, m_logo.transform);
}

void LoadingScene::onEnter() {
  // Debugging purposes
  AssetManager::getinstance()->getMapData();
}

void LoadingScene::onExit() {}

LoadingScene::~LoadingScene() {

}
