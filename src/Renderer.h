//
// Created by KOZY on 11/19/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "AssetManager.h"
#include "raylib.h"
#include "Utils.h"

class Renderer {
private:

public:
  Renderer() = default;
  ~Renderer() = default;

  // TODO: Implement sprite animation handling and rendering

  void renderTexture(const std::string& textureName, TransformEx transform, Color tint = WHITE) {
    // DrawTextureEx(
    //     texture,
    //     {
    //         transform.position.x,
    //         transform.position.y
    //     },
    //     transform.rotation,
    //     transform.scale,
    //     tint
    // );

    Texture2D tempTex = AssetManager::getinstance()->getTexture(textureName);

    DrawTextureEx(
        tempTex,
        {
            transform.position.x,
            transform.position.y
        },
        transform.rotation,
        transform.scale,
        tint
    );
  }

  // TODO: Maybe add external stuff like renderTexture()
  void renderText(const TextEx& textStruct) {
    DrawText(
        textStruct.text.c_str(),
        textStruct.position.x,
        textStruct.position.y,
        textStruct.fontSize,
        textStruct.tint
    );
  }

  // TODO: Maybe add external stuff like renderTexture()
  void renderRectangle(Rectangle rectangle, Color tint = WHITE) {
    DrawRectangleRec(rectangle, tint);
  }
};



#endif //RENDERER_H