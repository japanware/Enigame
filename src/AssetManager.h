//
// Created by KOZY on 11/11/2024.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <raylib.h>


class AssetManager {
private:
  std::unordered_map<std::string, Texture2D>      textureAssets;
  std::unordered_map<std::string, Font>           fontAssets;
  std::unordered_map<std::string, Sound>          soundAssets;

public:
  AssetManager() = default;
  ~AssetManager();

  bool checkExistingTexture(const std::string& fileName);
  void loadAssetImage(const std::string& fileName);

  bool checkExistingFont(const std::string& fontFileName);
  void loadAssetFont(const std::string& fontFileName);

  bool checkExistingSound(const std::string& fontFileName);
  void loadAssetSound(const std::string& soundFileName);

  static std::unique_ptr<AssetManager>& getinstance();

  // getTexture doesn't work for some reason? Can't find file. Needs to be looked in.
  Texture2D getTexture(const std::string& fileName);
  [[nodiscard]]int getTextureWidth(const std::string& fileName) const;
  [[nodiscard]]int getTextureHeight(const std::string& fileName) const;

  // Test method
  void getMapData() const;

  // void unloadAssetImage(const std::string& mapFileName);
};



#endif //ASSETMANAGER_H