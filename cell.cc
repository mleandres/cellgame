#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

using namespace std;

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

// return Info object with info of cell.
Info Cell::getInfo() const {
	return Info{r, c, isOn};
}

void Cell::setOn() {
	isOn = true;
}

void Cell::toggle() {
	if (isOn) isOn = false;
	else isOn = true;

	#ifdef DEBUG
	cerr << r << ", " << c << " is set to: " << (isOn ? "on" : "off") << endl;
	#endif

	notifyObservers(SubscriptionType::All);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

// cell gets notified
void Cell::notify(Subject &whoNotified) {
	toggle();
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
