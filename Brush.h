#pragma once
#include "Element.h"
class Brush
{
public:
	Brush(int rows, int cols, int cellSize,int brushSize, RenderWindow* refwindow);
	void GetInput();
private:
	typedef Element*(*ElementType)();
	ElementType* Elements; // for array of lambdas 
	int Selection = 0; // the selected element
	int BrushSize = 1; // the area of cells that will be affected
	int ElementsSize; // number of elements taht can be selected
	int Rows, Cols, CellSize; // used to scale mouse position 
	RenderWindow* window; // to get mouse 
	bool isMMPressed = false;
	void toggleSelection();
	void SpawnElement(int x, int y);
	void Erase(int x, int y);
};


