#pragma once
#include "Element.h"
class Wood :
    public Element
{
public:
    Wood();
    virtual void Update(int x, int y) override;
};

