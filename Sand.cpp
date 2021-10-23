#include "Sand.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;

Sand::Sand() {
	Name = "Sand";
	Colour = Color::Yellow;
}

 void Sand::Update(int x, int y) {
	 // move down if it's empty
	if (grid->isEmpty(x, y + 1)) {
		Move(x, y, x, y + 1);
		return;
	}
	// move down and left if it's empty
	else if (grid->isEmpty(x - 1, y + 1)) {
		Move(x, y, x - 1, y + 1);
		return;
	}
	//move down and right if it's empty
	else if (grid->isEmpty(x + 1, y + 1)) {
		Move(x, y, x + 1, y + 1);
		return;
	}
	IsStatic = true;
}