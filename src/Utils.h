//
// Created by KOZY on 11/11/2024.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "raylib.h"

typedef struct TransformEx {
  Vector2 position;
  float rotation;
  float scale = 1.0f;
} TransformEx;

typedef struct TextEx {
  std::string text;
  Vector2 position;
  int fontSize;
  Color tint = WHITE;
} TextEx;

typedef struct TextureEx {
  Texture2D textureFile;
  std::string textureName;
  TransformEx transform;
  Color tint = WHITE;
} TextureEx;

class Utils {
private:
  double lastUpdatedTime;

public:
  Utils();
  ~Utils() = default;

  bool eventTriggered(const double& interval);
};

#endif //UTILS_H