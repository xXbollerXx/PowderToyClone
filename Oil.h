#pragma once
#include "Element.h"
class Oil :
    public Element
{
public:
    Oil();
    virtual void Update(int x, int y) override;

};

