#include <iostream>
#include <new>
#include <vector>

// minimal C++11 allocator with debug ouput
template <class Tp>
struct NAlloc {
	typedef Tp value_type;
	NAlloc() = default;
	template <class T>
	NAlloc(const NAlloc<T>&) {}
	Tp* allocate(std::size_t n) {
		n *= sizeof(Tp);
		std::cout << "allocating " << n << " bytes\n";
		return static_cast<Tp*>(::operator new(n));
	}
	void deallocate(Tp* p, std::size_t n) {
		std::cout << "deallocating " << n * sizeof(*p) << "bytes\n";
		::operator delete(p);
	}
};

template <class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) {
	return true;
}
template <class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) {
	return false;
}

void vector_alloc() {
	int sz = 100;
	std::cout << "using reserve : \n";
	{
		std::vector<int, NAlloc<int>> v1;
		v1.reserve(sz);
		for (int n = 0; n < sz; ++n)
			v1.push_back(n);
	}
	std::cout << "not using reserve : \n";
	{
		std::vector<int, NAlloc<int>> v1;
		for (int n = 0; n < sz; ++n)
			v1.push_back(n);
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
	s.put('[');
	char comma[3] = {'\0', ' ', '\0'};
	for (const auto& e : v) {
		s << comma << e;
		comma[0] = ',';
	}
	return s << ']';
}

void vector_test() {
	std::vector<std::string> words1{"the", "forgurt", "is", "also", "cursed"};
	std::cout << "words1 : " << words1 << '\n';

	std::vector<std::string> words2(words1.begin(), words1.end());
	std::cout << "words2 : " << words2 << std::endl;

	std::vector<std::string> words3(words1);
	std::cout << "words3 : " << words3 << std::endl;

	std::vector<std::string> words4(5, "Mo");
	std::cout << "words4 : " << words4 << '\n';
}