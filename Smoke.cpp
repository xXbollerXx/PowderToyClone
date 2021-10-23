#include "Smoke.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;

Smoke::Smoke()
{
	Name = "Smoke";
	Colour = Color::Color(58, 58, 58);
	Density = 0;
}

void Smoke::Update(int x, int y)
{
	//try to move up
	if (grid->isEmpty(x, y - 1)) {
		Move(x, y, x, y - 1);
		return;
	}
	//try to move up and left
	else if (grid->isEmpty(x - 1, y - 1)) {
		Move(x, y, x - 1, y - 1);
		return;

	}
	//try to move up and right
	else if (grid->isEmpty(x + 1, y - 1)) {
		Move(x, y, x + 1, y - 1);
		return;

	}
	//try to move right
	else if (grid->isEmpty(x + 1, y)) {
		Move(x, y, x + 1, y);
		return;

	}
	//try to move left
	else if (grid->isEmpty(x - 1, y)) {
		Move(x, y, x - 1, y);
		return;

	}
	IsStatic = true;
}
