#ifndef QUEUE_H_
#define QUEUE_H_

#include <optional>
#include <queue>
#include "IObservable.h"


template <typename T>
class Queue : public IObservable
{
public:
	Queue() = default;
	virtual ~Queue() = default;

	void push(const T& pVal) {
		mQue.push(mVal = pVal);
		notifyObservers();
	}

	std::optional<T> pop() {
		if (mQue.empty()) {
			return {};
		}
		T front = mQue.front();
		mQue.pop();
		return front;
	}

	void notifyObservers() override { // IObservable implementation
		for (const auto& obs : getObservers()) {
			obs->update(mVal);
		}
	}

private:
	T mVal{};
	std::queue<T> mQue{};
};

#endif
