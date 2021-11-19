#include "../headers/TextureManager.h"

sf::Texture &TextureManager::getTexture(const int Id) {
    return Textures.at(Id);
}

void TextureManager::LoadTexture(const int Id, const std::string &Path) {
    if(Textures.find(Id)==Textures.end()){
        sf::Texture Texture_buf;
        Texture_buf.loadFromFile(Path);
        Textures[Id] = Texture_buf;
    }
}
