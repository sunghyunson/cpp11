#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

namespace ranges {
template <typename Range, typename Generator>
void generate(Range& range, Generator generator) {
	return std::generate(begin(range), end(range), generator);
}
} // namespace ranges



class RandomNumberBetween {
public:
	RandomNumberBetween(int low, int high) : m_random_engine(random_device{}()), m_distribution(low, high) {}
	int operator()() { return m_distribution(m_random_engine); }

private:
	mt19937 m_random_engine;
	uniform_int_distribution<int> m_distribution;
};

int main() {
	// random_device first_random_device;

	// mt19937 random_engine(first_random_device());
	// mt19937 random_engine(3);
	mt19937 random_engine(random_device{}());
	uniform_int_distribution<int> distribution(0, 10);
	// uniform_real_distribution<double> distribution(0, 10.01);

	auto randomGenerator = std::bind(distribution, random_engine);
	for (int i = 0; i < 10; i++) {
		// auto const randNumber = distribution(random_engine);
		// cout << randNumber << endl;
		cout << randomGenerator() << ' ';
	}
	cout << endl;
	auto const randNumber = random_engine() % 101;
	cout << "Random number: " << randNumber << endl;

	/*
		// std::vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	   "ten"}; std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; ranges::generate(numbers,
	   RandomNumberBetween(1, 100));
		// generate(begin(numbers), end(numbers), RandomNumberBetween(1, 100));
		for (const auto& num : numbers) {
			cout << num << ' ';
		}
		cout << endl;
	 */
}