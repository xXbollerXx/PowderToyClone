#pragma once
#include "Element.h"
class ParticleGrid
{
private:
	int Rows;
	int Cols;
public:
    Element*** Cells;
	ParticleGrid(int rows, int cols);
	~ParticleGrid();
	void Update();
	bool ValidPosition(int x, int y);
	bool isNull(int x, int y);
	bool isEmpty(int x, int y);
	bool ValidCell(int x, int y);
	void EraseCell(int x, int y);
	void Swap(int ax, int ay, int bx, int by);
	void Unfreeze(int x, int y);
	bool isLighter(int x, int y, int density);
	bool isHeavier(int x, int y, int density);
};

