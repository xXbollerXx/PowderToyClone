#pragma once
#include "Element.h"
 class Sand :
    public Element
{
public:
     Sand();
    virtual void Update(int x, int y) override;

};

