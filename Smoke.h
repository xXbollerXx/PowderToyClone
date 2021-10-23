#pragma once
#include "Element.h"
class Smoke :
    public Element
{
public:
    Smoke();
    virtual void Update(int x, int y) override;
};

