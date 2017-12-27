#ifndef SCENENODE_H
#define SCENENODE_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> SceneNodePtr;
    SceneNode();

    void attachChild(SceneNodePtr child);
    SceneNodePtr detachChild(const SceneNode& node);
    void update(sf::Time dt);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren (sf::Time dt);

    std::vector<SceneNodePtr> mChildren;
    SceneNode* mParent;
};

#endif // SCENENODE_H
