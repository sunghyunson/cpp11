#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <stdio.h>

using namespace std;

void runner(std::shared_future<void>* start, int id)
{
	start->get();
	// printf("\nstart : %d\n", id);
	std::cout << "출발 : " << id << '\n';
}

void jurge(std::promise<void>* p)
{
	std::cerr << "ready...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "Go!" << std::endl;

	p->set_value();
}

int main()
{
	std::promise<void> p;
	std::shared_future<void> start = p.get_future();

	thread runners[10];
	for (int i = 0; i < 10; i++)
	{
		runners[i] = thread(runner, &start, i);
	}
	// thread t1(runner, &start, 1);
	// thread t2(runner, &start, 2);
	// thread t3(runner, &start, 3);
	// thread t4(runner, &start, 4);

	// // cerr는 cout과 다르게 버퍼를 사용하지 않기 때문에 터미널에 바로 출력한다.
	// std::cerr << "ready...";
	// std::this_thread::sleep_for(std::chrono::seconds(1));
	// std::cerr << "Go!" << std::endl;

	// p.set_value();
	thread j1(jurge, &p);

	j1.join();
	// t1.join();
	// t4.join();
	// t2.join();
	// t3.join();
	for (int i = 0; i < 10; i++)
	{
		runners[i].join();
	}
}