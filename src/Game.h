//
// Created by KOZY on 11/11/2024.
//

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>

#include "Renderer.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "Utils.h"

class Game {
private:


  SceneManager sceneManager;
  Renderer renderer;

public:
  std::string titleName;

  Game();
  ~Game() = default;

  void update();
  void render();
  void run();

  Utils utils;
};



#endif //GAME_H