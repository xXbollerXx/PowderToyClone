#include "Water.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;

Water::Water() : Element()
{
	Name = "Water";
	Colour = Color::Blue;
	Density = 2;
}



void Water::Update(int x, int y)
{
	//try to move down 
	if (grid->isEmpty(x, y + 1) || grid->ValidCell(x, y + 1) && grid->isLighter(x, y+ 1, GetDensity())) {
		grid->Swap(x, y + 1, x, y);
		return;
	}
	//try to move down and left
	else if (grid->isEmpty(x - 1, y + 1) || grid->ValidCell(x - 1, y + 1) && grid->isLighter(x - 1, y + 1, GetDensity())) {
		grid->Swap(x -1, y + 1, x, y);
		return;
	}
	//try to move down and right
	else if (grid->isEmpty(x + 1, y + 1) || grid->ValidCell(x + 1, y + 1) && grid->isLighter(x + 1, y + 1, GetDensity())) {
		grid->Swap(x + 1, y + 1, x, y);
		return;
	}
	//try to move right
	else if (grid->isEmpty(x + 1, y)) {
		grid->Swap(x + 1, y, x, y);
		return;
	}
	//try to move left
	else if (grid->isEmpty(x - 1, y)) {
		grid->Swap(x - 1, y, x, y);
		return;
	}
	// try to move up
	else if (grid->ValidCell(x, y - 1) && grid->isHeavier(x, y- 1, GetDensity())) {
			grid->Swap(x, y - 1, x, y);
			return;
	}
	IsStatic = true;
}
