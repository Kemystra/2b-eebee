#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    virtual void use() = 0;
};

// Use when die()
class DyingComponent : public Component {
    void use() override;
};

// Use during look()
class LookComponent : public Component {
    void use() override;
};

// Use during move()
class MoveComponent : public Component {
    void use() override;
};

#endif  // COMPONENT_H
