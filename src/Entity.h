//
// Created by KOZY on 11/19/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <raylib.h>

#include "Renderer.h"

/*
 * @class Entity
 *
 * @brief Base class for derived classes (e.g. Player)
 *
 * This file provides the base functionality for all game entities.
 * Derived classes must implement the 'update()' method.
 */
class Entity {
protected:
  TransformEx                     m_entityTransform;
  std::string                     m_entityName;
  Texture2D                       m_entityTexture;

  // [[maybe_unused]] Rectangle      entityRectangle;

public:
  Entity(const std::string& name, const Texture2D& texture, const TransformEx& transform);
  virtual ~Entity() = default;

  // Virtual functions for derived classes to override for own entity behavior.
  virtual void update() = 0;
  virtual void render(Renderer& renderer);

};


#endif //ENTITY_H