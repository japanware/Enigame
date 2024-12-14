//
// Created by KOZY on 11/25/2024.
//

#ifndef SCENE_H
#define SCENE_H

#include "Renderer.h"

/*
 * @class Scene
 *
 * @brief Base blueprint for scenes
 *
 * This file provides basic methods for scenes, which acts as a blueprint
 * Derived classes must implement 'update()', 'render()' and the deconstructor.
 *
 */
class Scene {
public:
  virtual ~Scene() = default;

  virtual void update(float deltaTime) = 0;
  virtual void render(Renderer& renderer) = 0;
  virtual void onEnter() = 0;
  virtual void onExit() = 0;

};


#endif //SCENE_H