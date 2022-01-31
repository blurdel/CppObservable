#ifndef IOBSERVABLE_H_
#define IOBSERVABLE_H_

#include <set>
#include "IObserver.h"


class IObservable {
public:
	IObservable() {}
	virtual ~IObservable() {}

	virtual void notifyObservers() = 0; // implementation


	virtual void addObserver(IObserver& pObs) {
		mObservers.insert(&pObs);
	}

	virtual void removeObserver(IObserver& pObs) {
		mObservers.erase(&pObs);
	}

	std::set<IObserver*> getObservers() {
		return mObservers;
	}


private:
	std::set<IObserver*> mObservers;
};

#endif
