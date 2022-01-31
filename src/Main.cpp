#include <iostream>
#include <optional>
#include <thread>
#include <signal.h>

#include "Logger.h"
#include "Client.h"
#include "Queue.h"


bool running = true;
inline void stopHandler(int)
{
	running = false;
	std::cout << "Got signal to shutdown." << std::endl;
}
inline void setupSignalHandlers()
{
	signal(SIGINT,  stopHandler);
	signal(SIGTERM, stopHandler);
}

int main()
{
	std::cout << "Observable" << std::endl;
	setupSignalHandlers();


	Queue<int> que;
	Client one(1), two(2);

	que.addObserver(one);
	que.addObserver(two);

	que.push(42);
	que.push(99);
	que.push(111);

	for (int i = 0; i < 4; i++) {
		std::optional<int> x = que.pop();
		if (x.has_value()) {
			std::cout << "pop x = " << x.value() << std::endl;
		}
	}


	Logger logger;
	logger.addObserver(one);
	logger.addObserver(two);

	logger.logMsg("Hello world!");

	std::string input;
	while (running) {
		std::cout << "Enter a message to log (or just <ENTER> to quit) : " << std::endl;
		getline(std::cin, input);

		if (input.length() == 0) {
			break;
		}
		logger.logMsg(input);
	}

	std::cout << "Done." << std::endl;
	return 0;
}
