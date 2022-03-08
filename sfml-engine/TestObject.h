#pragma once
#include "GameObject.h"

#include <string>

class TestObject :
    public ae::GameObject
{
public:
    TestObject();
    virtual ~TestObject();

    bool eventHandler(const ae::Event* event);

    virtual void draw();

    std::string testString;

    virtual void update();

private:
    bool isMoveRight;
    bool isMoveLeft;
    bool isMoveUp;
    bool isMoveDown;
};

