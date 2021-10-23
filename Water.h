#pragma once
#include "Element.h"
class Water :
    public Element
{
public:
    Water();
    virtual void Update(int x, int y) override;
};

