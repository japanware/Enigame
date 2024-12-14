//
// Created by KOZY on 11/24/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <memory>
#include <unordered_map>
#include <iostream>
#include "Scene.h"


class SceneManager {
protected:
  std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
  std::shared_ptr<Scene> currentScene;

public:
  SceneManager() = default;
  virtual ~SceneManager() = default;

  virtual void addScene(const std::string& name, const std::shared_ptr<Scene>& scene);
  virtual void switchScene(const std::string& name);

  void update(float deltaTime);
  void render(Renderer& renderer);
};



#endif //SCENEMANAGER_H