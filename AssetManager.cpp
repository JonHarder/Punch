#include"AssetManager.hpp"


// requests a drawable from the manager, if it exists it
// just gets the pointer of the drawable and returns it
// key functions as the file source to be loaded
Drawable* AssetManager::addAsset(std::string imageSrc) {
    // only make new drawable if doesnt already exist
    // assets.emplace(imageSrc, new Drawable(imageSrc));
    if(assets[imageSrc] == 0) { 
        assets[imageSrc] = new Drawable(imageSrc);
    } 
    return assets[imageSrc];
}

void AssetManager::free(std::string key) {
    assets.erase(key);
}

Drawable* AssetManager::getAsset(std::string key) {
    return assets[key];
}
