#pragma once
#include "Element.h"
class Stone :
    public Element
{
public:
    Stone();
    virtual void Update(int x, int y) override;
};

