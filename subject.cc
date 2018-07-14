#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {
	observers.push_back(o);
}

Subject::~Subject() {}

void Subject::notifyObservers(SubscriptionType t) {
	// always want to notify text display
	// 	only want to notify a cell's observers when it is a "switch" in main

	for (auto n : observers) {
		if (n->subType() == t) n->notify(*this);
	}
}
