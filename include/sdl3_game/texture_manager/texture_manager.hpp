#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <string>
#include <unordered_map>

class Texture_Manager {
public:
    static SDL_Texture* load_texture(const std::string& filePath);
    static void unload_texture(const std::string& filePath);
    static void clear();

private:
    struct SDLTextureDeleter {
        void operator()(SDL_Texture* texture) const {
            if (texture) SDL_DestroyTexture(texture);
        }
    };

    using TexturePtr = std::unique_ptr<SDL_Texture, SDLTextureDeleter>;
    static std::unordered_map<std::string, TexturePtr> textures;
};

#endif
