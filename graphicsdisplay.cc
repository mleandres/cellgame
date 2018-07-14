#include "graphicsdisplay.h"
#include "cell.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int n) : xw{new Xwindow()}, gridSize{n},
	windowSize{500}, squareSize{(windowSize / gridSize)}
	{
	for (int i = 0; i < gridSize; ++i) {
		std::vector<bool> row;
		for (int j = 0; j < gridSize; ++j) {
			row.push_back(false);

			// now draw squares
			Info info{i, j, false};
			drawSquare(xw, info);

		}
		squares.push_back(row);
	}

}

// draws a black or white square with an opposite coloured border.
void GraphicsDisplay::drawSquare(Xwindow *xw, const Info &info) {
	int x = info.col * squareSize;
	int y = info.row * squareSize;
	int colour = (info.state ? Xwindow::White : Xwindow::Black);
	int border = (info.state ? Xwindow::Black : Xwindow::White);

	// square
	xw->fillRectangle(x, y, squareSize, squareSize, colour);
	// borders
	// north
	xw->fillRectangle(x, y, squareSize, 1, border);
	// south
	xw->fillRectangle(x, y + squareSize - 1, squareSize, 1, border);
	// east
	xw->fillRectangle(x, y, 1, squareSize, border);
	// west
	xw->fillRectangle(x + squareSize - 1, y, 1, squareSize, border);
}

GraphicsDisplay::~GraphicsDisplay() {
	delete xw;
}

// notifiy graphics display that something happened!
void GraphicsDisplay::notify(Subject &whoNotified) {
	Info info = whoNotified.getInfo();
	drawSquare(xw, info);
	squares[info.row][info.col] = info.state;
}

SubscriptionType GraphicsDisplay::subType() const {
	return SubscriptionType::All;
}
