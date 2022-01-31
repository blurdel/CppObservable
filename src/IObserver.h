#ifndef _SRC_IOBSERVER_
#define _SRC_IOBSERVER_


class IObserver {
public:
	IObserver() {}
	virtual ~IObserver() {}

	virtual void update() = 0;

	virtual void update(int pData) = 0;

	virtual void update(std::string pMsg) = 0;

};

#endif
