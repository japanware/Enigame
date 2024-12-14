//
// Created by KOZY on 11/11/2024.
//

#include "Game.h"

#include "IntroScene.h"
#include "LoadingScene.h"

Game::Game() : titleName("CUM ENGINE 0.1b")
{}


void Game::update() {
  float deltaTime = GetFrameTime();

  sceneManager.update(deltaTime);
}

void Game::render() {
  BeginDrawing();
  ClearBackground(WHITE);

  sceneManager.render(renderer);

  EndDrawing();
}

void Game::run() {
  InitWindow(1080, 720, titleName.c_str());
  SetTargetFPS(60);

  sceneManager.addScene("loadingScene", std::make_shared<LoadingScene>());
  sceneManager.switchScene("loadingScene");

  while (WindowShouldClose() == false){
    update();
    render();
  }

  CloseWindow();
}