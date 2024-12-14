//
// Created by KOZY on 11/11/2024.
//

#include "AssetManager.h"

#include <utility>


// Deconstructor: Goes through all maps, which store the assets (Textures, fonts and sounds)
AssetManager::~AssetManager() {
    for (const auto& it : textureAssets) {
        UnloadTexture(it.second);
    }
    for (const auto& it : fontAssets) {
        UnloadFont(it.second);
    }
    for (const auto& it : soundAssets) {
        UnloadSound(it.second);
    }
    std::cout << "AssetManager::~AssetManager: All assets have been released\n";
}

// Finds texture. If not found, return error (true) else returns false
bool AssetManager::checkExistingTexture(const std::string& fileName) {
    auto it = textureAssets.find(fileName);

    if (it != textureAssets.end()) {
        std::cerr << "AssetManager::checkExistingTexture: File already exists: " << fileName << "\n";
        return true;
    }
    return false;
}

// First checks if texture (filename as parameter) exists. If not (if false)
// Combines current working path + path to the images / textures.
// Inserts texture into unordered_map.
void AssetManager::loadAssetImage(const std::string& fileName) {
    if (!checkExistingTexture(fileName)) {
        std::string filePath = std::filesystem::current_path().string() + "/src/assets/img/" + fileName;

        Image tempImage = LoadImage(filePath.c_str());

        if (!IsImageReady(tempImage)) {
            std::cerr << "AssetManager::loadAssetImage: Failed to load image: " << fileName << "\n";
            return;
        }

        Texture2D tempTex = LoadTextureFromImage(tempImage);
        textureAssets.insert({
            fileName,
            tempTex
        });

        UnloadImage(tempImage);
    }
}

bool AssetManager::checkExistingFont(const std::string &fontFileName) {
    auto it = fontAssets.find(fontFileName);

    if (it != fontAssets.end()) {
        std::cerr << "AssetManager::checkExistingFont: File already exists: " << fontFileName << "\n";
        return true;
    }
    return false;
}

void AssetManager::loadAssetFont(const std::string &fontFileName) {
    if (!checkExistingFont(fontFileName)) {
        std::string filePath = std::filesystem::current_path().string() + "/src/assets/font/" + fontFileName;

        Font tempFont = LoadFont(filePath.c_str());

        if (!IsFontReady(tempFont)) {
            std::cerr << "AssetManager::loadAssetFont: Failed to load font: " << fontFileName << "\n";
            return;
        }

        fontAssets.insert({
            fontFileName,
            tempFont
        });
    }
}

bool AssetManager::checkExistingSound(const std::string &fontFileName) {
    auto it = soundAssets.find(fontFileName);

    if (it != soundAssets.end()) {
        std::cerr << "AssetManager::checkExistingSound: Sound already exists: " << fontFileName << "\n";
        return true;
    }
    return false;
}

void AssetManager::loadAssetSound(const std::string &soundFileName) {
    if (!checkExistingSound(soundFileName)) {
        std::string filePath = std::filesystem::current_path().string() + "/src/assets/sound/" + soundFileName;

        Sound tempSound = LoadSound(filePath.c_str());

        if (!IsSoundReady(tempSound)) {
            std::cerr << "AssetManager::loadAssetSound: Failed to load sound: " << soundFileName << "\n";
            return;
        }

        soundAssets.insert({
            soundFileName,
            tempSound
        });
    }
}

Texture2D AssetManager::getTexture(const std::string &fileName) {
  auto it = textureAssets.find(fileName);

  if (it != textureAssets.end()) {
    return it->second;
  }

  std::cerr << "AssetManager::getTexture: Texture not found: " << fileName << "\n";
  return {};
}

int AssetManager::getTextureWidth(const std::string &fileName) const {
    auto it = textureAssets.find(fileName);

    if (it != textureAssets.end()) {
        return it->second.width;
    }
    std::cerr << "AssetManager::getTextureWidth: Texture not found: " << fileName << "\n";
    return {};
}


int AssetManager::getTextureHeight(const std::string &fileName) const {
    auto it = textureAssets.find(fileName);

    if (it != textureAssets.end()) {
        return it->second.height;
    }
    std::cerr << "AssetManager::getTextureHeight: Texture not found: " << fileName << "\n";
    return {};
}

std::unique_ptr<AssetManager> &AssetManager::getinstance() {
    static std::unique_ptr<AssetManager> instance = std::make_unique<AssetManager>();
    return instance;
}

// Just returns all data from texture map. Just for debugging purposes.
// TODO: Gotta add font and sound maps
void AssetManager::getMapData() const {
    for (const auto& it : textureAssets) {
        std::cout << "Key: " << it.first << "\n";
    }
}


// [[maybe_unused]] void AssetManager::unloadAssetImage(const std::string &fileName) {
//     auto it = assets.find(fileName);
//
//     if (it != assets.end()) {
//         UnloadTexture(it->second);
//         std::cout << "AssetManager: Successfully unloaded asset: " << "\n";
//         assets.erase(it);
//     } else {
//         std::cerr << "AssetManager: Failed to unload asset: " << "\n";
//     }
// }