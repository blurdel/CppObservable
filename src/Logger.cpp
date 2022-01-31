#include "Logger.h"


Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::logMsg(std::string pMsg) {
	mMsg = pMsg;
	notifyObservers();
}

void Logger::notifyObservers() {
	for (const auto& obs : getObservers()) {
		obs->update(mMsg);
	}
}
