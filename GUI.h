#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleGrid.h"
extern ParticleGrid* grid;
using namespace sf;

class GUI
{
private:
	int Rows;
	int Cols;
	int CellSize;
	RenderWindow* window;
	RectangleShape** Cells;
public:
	GUI(int rows, int cols, int cellSize, RenderWindow* refwindow);
	~GUI();
	void DisplayGrid();
};

