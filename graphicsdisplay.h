#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "window.h"
#include "observer.h"
#include "info.h"

class Cell;

class GraphicsDisplay: public Observer {
	Xwindow *xw;
	const int gridSize; // could be useful
	std::vector<std::vector<bool>> squares;

	// total height and width of window
	const int windowSize;

	// height and width of each square
	const int squareSize;

  // draws one square with a border
  void drawSquare(Xwindow *xw, const Info &info);

public:
	GraphicsDisplay(int n); // Constructor with n for gridSize

	void notify(Subject &whoNotified);
	SubscriptionType subType() const override;

	~GraphicsDisplay();
};


#endif
