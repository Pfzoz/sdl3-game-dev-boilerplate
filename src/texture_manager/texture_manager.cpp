#include "sdl3_game/texture_manager/texture_manager.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <unordered_map>

std::unordered_map<std::string, std::unique_ptr<SDL_Texture, Texture_Manager::SDLTextureDeleter>> Texture_Manager::textures =
    std::unordered_map<std::string, std::unique_ptr<SDL_Texture, Texture_Manager::SDLTextureDeleter>>();

SDL_Texture* Texture_Manager::load_texture(const std::string &file_path) {
    App_State *context = App_State::init_state();
    if (textures[file_path] != nullptr) {
        return textures[file_path].get();
    }
    SDL_Surface *surface = NULL;
    surface = IMG_Load(file_path.c_str());
    if (surface == NULL) {
        printf("Error loading texture. File Path: %s Message: %s\n", file_path.c_str(), SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(context->renderer, surface);
    SDL_DestroySurface(surface);
    if (texture == NULL) {
        printf("Error creating texture from surface: %s\n", SDL_GetError());
    }
    textures[file_path] = std::unique_ptr<SDL_Texture, SDLTextureDeleter>(texture, SDLTextureDeleter());
    return texture;
}

void Texture_Manager::unload_texture(const std::string &file_path) {
    SDL_Texture *texture = textures[file_path].get();
    if (texture != nullptr) {
        textures.erase(file_path);
    }
}

void Texture_Manager::clear() {
    textures.clear();
}
