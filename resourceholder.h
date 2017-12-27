#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <string>
#include <map>
#include <assert.h>
#include <memory>
#include <iostream>
#include "textures.h"



template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void loadResource(Identifier id,const std::string filename)
    {
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename)) {
            throw std::runtime_error ("Resource Holder load failed to load: " + filename);
        } else {
            std::cout << "Loaded resource: " << filename << std::endl;
        }

        auto inserted = mResourceMap.insert(std::make_pair(id,std::move(resource)));
        assert(inserted.second);
    }

    Resource& get(Identifier id)
    {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }

    const Resource& get(Identifier id) const
    {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }

private:
     std::map<Identifier,std::unique_ptr<Resource>> mResourceMap;
};

typedef ResourceHolder<sf::Texture,Textures::ID> TextureHolder;
#endif // RESOURCEHOLDER_H
