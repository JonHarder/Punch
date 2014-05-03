#ifndef _ASSET_MANAGER_H
#define _ASSET_MANAGER_H

#include<map>
#include"Drawable.hpp"

class AssetManager {
public:
    Drawable* getAsset(std::string key);
    Drawable* addAsset(std::string imageSrc);
    void free(std::string key);
private:
    std::map<std::string, Drawable*> assets;
};

#endif // _ASSET_MANAGER_H
