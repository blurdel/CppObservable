#ifndef LOGGER_H_
#define LOGGER_H_

#include "IObservable.h"


class Logger : public IObservable {
public:
	Logger();
	virtual ~Logger();

	void logMsg(std::string pMsg);

	void notifyObservers() override; // IObservable implementation

private:
	std::string mMsg;
};

#endif
