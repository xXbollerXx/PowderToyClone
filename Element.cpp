#include "Element.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;
Element::Element()
{
	Name = "Empty";
}

string Element::GetName()
{
	return Name;
}

Color Element::GetColour()
{
	return Colour;
}


int Element::GetDensity()
{
	return Density;
}

void Element::Move(int x, int y, int newx, int newy)
{
	grid->Cells[newx][newy] = this;
	grid->Cells[x][y] = NULL;
	grid->Unfreeze(x, y);
	grid->Unfreeze(newx, newy);
}

bool Element::GetisFlammable()
{
	return isFlammable;
}

int Element::GetFuel()
{
	return Fuel;
}

void Element::Update(int x, int y)
{
}

