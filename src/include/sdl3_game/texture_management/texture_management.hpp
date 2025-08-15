#pragma once

#include <string>

struct SDL_Texture;

namespace Game::Textures {
    SDL_Texture* load_texture(const std::string& filePath);
    void unload_texture(const std::string& filePath);
    void clear_textures();
}
