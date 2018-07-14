#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid() {}

Grid::~Grid() {
	delete gd;
}

void Grid::clearGrid() {
	for (auto i : theGrid) {
		for (auto j : i) {
			i.pop_back();
		}
		theGrid.pop_back();
	}
	gridSize = 0;
}

bool Grid::isWon() const {
	for (auto i : theGrid) {
		// i is a row of cells
		for (auto j : i) {
			// j is a single cell
			if (j.getState()) return false;
		}
	}
	return true;
}

// sets up all cells with neighbours and text display with all cells
void Grid::init(int n) {
	if (gridSize != 0) clearGrid();
	gridSize = n;

	#ifdef DEBUG
	cerr << 1 << endl;
	#endif

	gd = new GraphicsDisplay(n);

	#ifdef DEBUG
	cerr << 2 << endl;
	#endif

	// rows
	for (int i = 0; i < n; ++i) {
		std::vector<Cell> row;
		// columns
		for (int j = 0; j < n; ++j) {
			row.push_back(Cell());
			// text display put in "0" spot in observer vecs
			row.back().attach(gd);
			row.back().setCoords(i, j);
		}
		theGrid.push_back(row);
	}

	// now attach adjacent cells
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// north
			if (i > 0) theGrid[i][j].attach(&theGrid[i-1][j]);
			// south
			if (i < n - 1) theGrid[i][j].attach(&theGrid[i+1][j]);
			// east
			if (j < n - 1) theGrid[i][j].attach(&theGrid[i][j+1]);
			// west
			if (j > 0) theGrid[i][j].attach(&theGrid[i][j-1]);
		}
	}
}

void Grid::turnOn(int r, int c) {

	#ifdef DEBUG
	cerr << "r is: " << r << endl;
	cerr << "c is: " << c << endl;
	#endif

  theGrid[r][c].setOn();
  theGrid[r][c].notifyObservers(SubscriptionType::All);
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);
}

