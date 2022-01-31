#include "Client.h"


Client::Client(int pId) : mId(pId) {
}

Client::~Client() {
}

void Client::update() {
	std::cout << "Client " << mId << " observe" << std::endl;
}

void Client::update(int pData) {
	std::cout << "Client " << mId << " observe data = " << pData << std::endl;
}

void Client::update(std::string pMsg) {
	std::cout << "Client " << mId << " observe data = " << pMsg << std::endl;
}
