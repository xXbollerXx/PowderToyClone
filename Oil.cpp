#include "Oil.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;
Oil::Oil()
{
	Name = "Oil";
	Colour = Color::Color(218, 60, 29);
	Density = 1;
	isFlammable = true;
	Fuel = 3;
}


void Oil::Update(int x, int y)
{
	//try to move down 
	if (grid->isEmpty(x, y + 1) || grid->ValidCell(x, y + 1) && grid->isLighter(x, y + 1, GetDensity())) {
		grid->Swap(x, y + 1, x, y);
		return;
	}
	//try to move down and left
	else if (grid->isEmpty(x - 1, y + 1) || grid->ValidCell(x - 1, y + 1) && grid->isLighter(x - 1, y + 1, GetDensity())) {
		grid->Swap(x - 1, y + 1, x, y);
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
	else if (grid->ValidCell(x, y - 1) && grid->isHeavier(x, y - 1, GetDensity())) {
		grid->Swap(x, y - 1, x, y);
		return;
	}
	IsStatic = true;
}
