#include "Stone.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;

Stone::Stone()
{
	Name = "Stone";
	Colour = Color::Color(107,107,107);
}

void Stone::Update(int x, int y)
{
	//try to move down
	if (grid->isEmpty(x, y + 1)) {
		Move(x, y, x, y + 1);
	}
	IsStatic = true;
}
