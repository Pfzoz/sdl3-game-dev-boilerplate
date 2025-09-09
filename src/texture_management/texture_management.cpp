#include "sdl3_game/texture_management/texture_management.hpp"
#include "sdl3_game/states/game.hpp"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <unordered_map>

struct SDL_Texture_Deleter {
  void operator()(SDL_Texture* texture) { SDL_DestroyTexture(texture); }
};

std::unordered_map<std::string, std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>> textures;

SDL_Texture* Game::Textures::load_texture(const std::string &file_path) {
    if (textures[file_path] != nullptr) {
        return textures[file_path].get();
    }
    SDL_Surface *surface = NULL;
    surface = IMG_Load(file_path.c_str());
    if (surface == NULL) {
        printf("Error loading texture. File Path: %s Message: %s\n", file_path.c_str(), SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::get_renderer(), surface);
    SDL_DestroySurface(surface);
    if (texture == NULL) {
        printf("Error creating texture from surface: %s\n", SDL_GetError());
    }
    textures[file_path] = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>(texture);
    return texture;
}

void Game::Textures::unload_texture(const std::string &file_path) {
    SDL_Texture *texture = textures[file_path].get();
    if (texture != nullptr) {
        textures.erase(file_path);
    }
}

void Game::Textures::clear_textures() {
    textures.clear();
}
