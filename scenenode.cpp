#include "scenenode.h"
#include <assert.h>

SceneNode::SceneNode()
{
    mParent = nullptr;
}

void SceneNode::attachChild(SceneNode::SceneNodePtr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(),mChildren.end(),[&](SceneNodePtr& p) -> bool {return p.get() == &node;});
    assert (found != mChildren.end());

    SceneNodePtr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target,states);

    for (const SceneNodePtr& child: mChildren) {
        child->draw(target,states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void SceneNode::updateCurrent(sf::Time dt)
{

}

void SceneNode::updateChildren(sf::Time dt)
{
    for (const SceneNodePtr& child: mChildren) {
        child->update(dt);
    }
}
