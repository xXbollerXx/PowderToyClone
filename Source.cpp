#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Source.h"
#include "GUI.h"
#include "ParticleGrid.h"
#include "Brush.h"
#include <chrono>
#include <iostream>
using namespace sf;

ParticleGrid* grid;
GUI* gui;


void GUIDisplay() {

	int Rows = 600;
	int Cols = 500;
	int CellSize = 2;

	RenderWindow window(VideoMode(Rows * CellSize, Cols * CellSize), "MyWindow", Style::Default);
	//window.setFramerateLimit(60);
	
    gui = new GUI(Rows, Cols, CellSize, &window); // grid to display the elements as pixels
	grid = new ParticleGrid(Rows, Cols); // grid to store elements and thier positions
	Brush* brush = new Brush(Rows, Cols, CellSize,6, &window); //class to handle user input

	while (window.isOpen()) // update loop 
	{
		auto startPoint = std::chrono::high_resolution_clock::now(); // get starting time 

		//handle normal window events
		Event evnt;
		while (window.pollEvent(evnt))
		{
			// close the window if the close button's pressed
			if (evnt.type == Event::Closed)
			{
				window.close();
			}
		} 

		window.clear(Color::Black); // clear the screen 
		brush->GetInput(); // get user input 
		grid->Update(); // update all elements 
		gui->DisplayGrid(); // display to screen 

		auto endPoint = std::chrono::high_resolution_clock::now(); // get ending time 

		//cal duration in ms and display
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();
		auto duration = end - start;
		double ms = duration * 0.001;
		std::cout << ms << "\n";
	}
	// window closed so clean up 
	delete gui;
	gui = NULL;
	delete grid;
	grid = NULL;
	delete brush;
	brush = NULL;
}



int main() {
	GUIDisplay();
	return 0;
}