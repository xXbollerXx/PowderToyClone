#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class Element
{
protected:
	 string Name;
	 Color Colour;
	 int Density = 3; // used to control how elements move
	 bool isFlammable = false; // if this type can burn 
	 int Fuel = 0; // used to control fire element 
	void Move(int x, int y, int newx, int newy);

public:
	bool IsStatic = false; // to optimize update function 
	 bool beenUpdated = true; // to stop from updating more than once per update
	
	Element();
	virtual void Update(int x, int y);
	string GetName();
	Color GetColour();
	int GetDensity();
	bool GetisFlammable();
	int GetFuel();
};

