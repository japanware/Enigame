//
// Created by KOZY on 11/19/2024.
//

#include "Entity.h"


Entity::Entity(const std::string &name, const Texture2D &texture, const TransformEx& transform)
    : m_entityTransform(transform), m_entityName(name), m_entityTexture(texture)  {}

void Entity::render(Renderer &renderer) {
  // renderer.renderTexture(
  //     m_entityTexture,
  //     {
  //         m_entityTransform.position.x,
  //         m_entityTransform.position.y
  //     }
  // );
}