#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <string>
#include <map>
#include <assert.h>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void loadResource(Identifier id,const std::string filename)
    {
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename)) {
            throw std::runtime_error ("Resource Holder load failed to load: " + filename);
        }

        auto inserted = mResourceMap.insert(std::make_pair(id,std::move(resource)));
        assert(inserted.second);
    }

    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;

private:
     std::map<Identifier,std::unique_ptr<Resource>> mResourceMap;
};



template<typename Resource, typename Identifier>
Resource &ResourceHolder<Resource,Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource &ResourceHolder<Resource,Identifier>::get(Identifier id) const
{

}

#endif // RESOURCEHOLDER_H
