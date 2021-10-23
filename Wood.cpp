#include "Wood.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;
Wood::Wood()
{
	Name = "Wood";
	Colour = Color::Color(150, 75, 0);
	Density = -1;
	isFlammable = true;
	Fuel = 10;
}

void Wood::Update(int x, int y)
{
	// if any element around is water. delete it and spawn new wood
	if (grid->ValidCell(x, y - 1) && grid->Cells[x][y - 1]->GetName() == "Water") {
		delete grid->Cells[x][y - 1];
		grid->Cells[x][y - 1] = new Wood();
	}
	if (grid->ValidCell(x, y + 1) && grid->Cells[x][y + 1]->GetName() == "Water") {
		delete grid->Cells[x][y + 1];
		grid->Cells[x][y + 1] = new Wood();
	}
	if (grid->ValidCell(x + 1, y) && grid->Cells[x + 1][y]->GetName() == "Water") {
		delete grid->Cells[x + 1][y];
		grid->Cells[x + 1][y] = new Wood();
	}
	if (grid->ValidCell(x - 1, y) && grid->Cells[x - 1][y]->GetName() == "Water") {
		delete grid->Cells[x - 1][y];
		grid->Cells[x - 1][y] = new Wood();
	}
	IsStatic = true;
}
