#include "Brush.h"
#include "Wood.h"
#include "Fire.h"
#include "Smoke.h"
#include "Sand.h"
#include "Stone.h"
#include "Water.h"
#include "Oil.h"
#include "ParticleGrid.h"
extern ParticleGrid* grid;

Brush::Brush(int rows, int cols, int cellSize, int brushSize, RenderWindow* refwindow) :Rows(rows), Cols(cols), CellSize(cellSize), BrushSize(brushSize), ElementsSize(7), window(refwindow)
{
	//array of lambdas to spawn new elemets
	Elements = new Brush::ElementType[ElementsSize]{
		[]() {return dynamic_cast<Element*>(new Sand()); },
		[]() {return dynamic_cast<Element*>(new Water()); },
		[]() {return dynamic_cast<Element*>(new Stone()); },
		[]() {return dynamic_cast<Element*>(new Wood()); },
		[]() {return dynamic_cast<Element*>(new Fire()); },
		[]() {return dynamic_cast<Element*>(new Smoke()); },
		[]() {return dynamic_cast<Element*>(new Oil()); },
	};
}

void Brush::toggleSelection()
{
	//increment selection or loop back if its max
	Selection++;
	if (Selection == ElementsSize) {
		Selection = 0;
	}
}

void Brush::SpawnElement(int x, int y)
{
	//use brush size to loop through area 
	for (int i = BrushSize * -1; i <= BrushSize; i++)
	{
		for (int j = BrushSize * -1; j <= BrushSize; j++)
		{
			// if cell is empty
			if (grid->isEmpty(x + i, y + j)) {
				//use lambda to instantiate Selected element 
				grid->Cells[x + i][y + j] = Elements[Selection](); 
			}
		}
	}
}

void Brush::Erase(int x, int y)
{
	//use brush size to loop through area 
	for (int i = BrushSize * -1; i <= BrushSize; i++)
	{
		for (int j = BrushSize * -1; j <= BrushSize; j++)
		{
			grid->EraseCell(x + i, y + j); // try to delete cell 
		}
	}
}

void Brush::GetInput()
{
	Vector2i position = Mouse::getPosition(*window); // get mouse position relative to screen 
	//if mouse is inside screen
	if (position.x >= 0 && position.y >= 0 && position.x < Rows * CellSize && position.y < Cols * CellSize) {
		//scale position from pixels to grid cells
		int x = (position.x / CellSize);
		int y = (position.y / CellSize);

		// spawn new element if left click 
		if (Mouse::isButtonPressed(Mouse::Left)) {
			SpawnElement(x, y);
		}
		//erase if right click 
		if (Mouse::isButtonPressed(Mouse::Right)) {
			Erase(x, y);
		}
		//change selection if middle mouse click
		if (Mouse::isButtonPressed(Mouse::Middle)) {
			// if MMB was pressed last update call then ignore
			if (!isMMPressed) {
				toggleSelection();
				isMMPressed = true;
			}
		}
		else {
			isMMPressed = false;
		}
	}
}

