#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include "IObserver.h"


class Client : public IObserver
{
public:
	Client(int pId);
	virtual ~Client();

	void update() override;
	void update(int pData) override;
	void update(std::string pMsg) override;

private:
	int mId;
};

#endif
