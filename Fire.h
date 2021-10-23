#pragma once
#include "Element.h"
class Fire :
    public Element
{
private:
    int Life = 10;
    void Burn(int x, int y, int fuel);
public:
    Fire(); // default fire 
    Fire(int lifeTime); // life time - how long it will live before turning into smoke
    virtual void Update(int x, int y) override;
};

