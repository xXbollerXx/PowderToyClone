#include "Fire.h"
#include "Smoke.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;
Fire::Fire()
{
	Name = "Fire";
	Colour = Color::Color(255, 165, 0);
	Density = -1;
}

Fire::Fire(int lifeTime) 
{
	Name = "Fire";
	Colour = Color::Color(255, 165, 0);
	Life = lifeTime;
	Density = -1;

}

void Fire::Burn(int x, int y, int fuel)
{
	//delete old element
	grid->EraseCell(x, y);
	//spawn new fire
	grid->Cells[x][y] = new Fire(fuel);
}

void Fire::Update(int x, int y)
{
	// if the lifetime of this cell is 0
	if (Life <= 0) {
		
		//if there is anything flammable around then burn it 
		if (grid->ValidCell(x, y - 1) && grid->Cells[x][y - 1]->GetisFlammable()) {
			Burn(x, y - 1, grid->Cells[x][y - 1]->GetFuel());
		}
		 if (grid->ValidCell(x, y + 1) && grid->Cells[x][y + 1]->GetisFlammable()) {
			Burn(x, y + 1, grid->Cells[x][y + 1]->GetFuel());

		}
		 if (grid->ValidCell(x + 1, y ) && grid->Cells[x + 1][y ]->GetisFlammable()) {
			Burn(x + 1, y, grid->Cells[x + 1][y]->GetFuel());

		}
		 if (grid->ValidCell(x - 1, y ) && grid->Cells[x -1][y ]->GetisFlammable()) {
			Burn(x - 1, y, grid->Cells[x - 1][y]->GetFuel());
		}
		 //spawn new smoke on my position 
		 grid->Cells[x][y] = new Smoke();
		 delete this; 
	}
	//decrement life 
	Life--;
}
