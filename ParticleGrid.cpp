#include "ParticleGrid.h"
ParticleGrid::ParticleGrid(int rows, int cols) : Rows(rows), Cols(cols)
{
	//build 2d array and fill with null pointers
	Cells = new Element ** [Rows];

	for (int i = 0; i < Rows; i++)
	{
		Cells[i] = new Element*[Cols];
		for (int j = 0; j < Cols; j++)
		{
			Cells[i][j] = NULL;
		}
	}
}

ParticleGrid::~ParticleGrid()
{
	for (int i = 0; i < Rows; i++)
	{
		delete[] Cells[i];
	}
	delete[] Cells;
	Cells = NULL;
}

void ParticleGrid::Update()
{
	//loop through array and update cells
	for (int i = Rows -1; i >= 0; i--)
	{
		for (int j = Cols - 1; j >=0; j--)
		{
			// not null, not static and hasent been updated this loop
			if (Cells[i][j] != NULL && !Cells[i][j]->IsStatic && !Cells[i][j]->beenUpdated) {
				Cells[i][j]->beenUpdated = true;
				Cells[i][j]->Update(i, j);
			}
		}
	}

	//reset beenupdated variable
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Cells[i][j] != NULL) {
				Cells[i][j]->beenUpdated = false;
			}
		}
	}
}


// if position is inside the grid then return true
bool ParticleGrid::ValidPosition(int x, int y)
{
	if ( x >= 0 && x < Rows && y >= 0 && y < Cols) {
		return true;
	}
	return false;
}

//if cell is a null pointer then return true
bool ParticleGrid::isNull(int x, int y)
{
	if (Cells[x][y] == NULL) {
		return true;
	}
	return false;
}

// if location has null pointer then return true
bool ParticleGrid::isEmpty(int x, int y)
{
	if (ValidPosition(x, y) && isNull(x, y)) {
		return true;
	}
	return false;
}

// if location does not have null pointer then return true
bool ParticleGrid::ValidCell(int x, int y)
{
	if (ValidPosition(x, y) && !isNull(x, y)) {
		return true;
	}
	return false;
}

// if location is valid, delete and clean up
void ParticleGrid::EraseCell(int x, int y)
{
	if (ValidCell(x, y)) {
		delete Cells[x][y];
		Cells[x][y] = NULL;
	}
	Unfreeze(x, y);
}

//swap the pointer between 2 locations 
void ParticleGrid::Swap(int ax, int ay, int bx, int by)
{
	Element* Temp = Cells[ax][ay];
	Cells[ax][ay] = Cells[bx][by];
	Cells[bx][by] = Temp;
	Unfreeze(ax, ay);
	Unfreeze(bx, by);
}

// reset the isStatic variable in a 3 x 3 area around location 
void ParticleGrid::Unfreeze(int x, int y)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (ValidCell(x + i, y + j)) {
				Cells[x + i][y + j]->IsStatic = false;
			}
		}
	}
}

//if other location's density is less than but greater than -1 
bool ParticleGrid::isLighter(int x, int y, int density)
{
	if (Cells[x][y]->GetDensity() < density && Cells[x][y]->GetDensity() > -1) {
		return true;
	}
	return false;
}

//if other location's density is greater
bool ParticleGrid::isHeavier(int x, int y, int density)
{
	if (Cells[x][y]->GetDensity() > density) {
		return true;
	}
	return false;
}





