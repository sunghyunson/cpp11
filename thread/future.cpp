#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void worker(std::promise<std::string>* p)
{
	std::this_thread::sleep_for(std::chrono::seconds(11));
	p->set_value(std::string("good morning"));
}

int main()
{
	std::promise<std::string> p;

	std::future<std::string> data = p.get_future();

	std::thread thread(worker, &p);

	while (true)
	{
		std::future_status status = data.wait_for(std::chrono::seconds(5));

		if (status == std::future_status::timeout)
		{
			std::cerr << "wait for time out wait more " << endl;
		}
		else if (status == std::future_status::ready)
		{
			cout << "result : " << data.get() << endl;
			break;
		}
	}
	thread.join();
}