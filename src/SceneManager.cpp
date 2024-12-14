//
// Created by KOZY on 11/24/2024.
//

#include "SceneManager.h"

void SceneManager::addScene(const std::string &name, const std::shared_ptr<Scene> &scene) {
  scenes[name] = scene;
}

void SceneManager::switchScene(const std::string &name) {
  if (scenes.contains(name)) {
    if (currentScene) {
      currentScene->onExit();
    }
    currentScene = scenes[name];
    currentScene->onEnter();
  } else {
    std::cout << "SceneManager::switchTo: Scene not found: " << name << "\n";
  }
}

void SceneManager::update(float deltaTime) {
  currentScene->update(deltaTime);
}

void SceneManager::render(Renderer &renderer) {
  currentScene->render(renderer);
}
