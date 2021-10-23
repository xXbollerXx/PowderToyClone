#include "GUI.h"
GUI::GUI(int rows, int cols, int cellSize, RenderWindow* refwindow) : Rows(rows), Cols(cols), CellSize(cellSize), window(refwindow) {
	//build 2d array of squares
	Cells = new RectangleShape * [Rows];

	for (int i = 0; i < Rows; i++)
	{
		Cells[i] = new RectangleShape[Cols];
		for (int j = 0; j < Cols; j++)
		{
			Cells[i][j] = RectangleShape(Vector2f(CellSize, CellSize)); // set square size
			Cells[i][j].setPosition(i * CellSize, j * CellSize); // set position
			Cells[i][j].setFillColor(Color::Black); // set colour to black 
			window->draw(Cells[i][j]);
		}
	}
	window->display();
}

GUI::~GUI()
{
	for (int i = 0; i < Rows; i++)
	{
		delete[] Cells[i];
	}
	delete[] Cells;
	Cells = NULL;
}


void GUI::DisplayGrid()
{
	//loop through element grid
	for (int i = 0; i < Rows ; i++)
	{
		for (int j = 0; j < Cols ; j++)
		{
			//if cell is valid then change GUI cell colour to element's colour and display
			if (grid->Cells[i][j] != NULL) {
				Cells[i][j].setFillColor(grid->Cells[i][j]->GetColour());
				window->draw(Cells[i][j]);
			}
		}
	}
	window->display();
}