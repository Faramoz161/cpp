#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void shell_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();
	size_t size = array.size();

	size_t d = size / 2;
	while(d > 0) {
		for(size_t i = d; i < size; i++)
			for (size_t j = i; j >= d && array[j] < array[j - d]; j-= d)
				swap(array[j], array[j - d]);
		d /= 2;
	}

	auto timer_end = chrono::steady_clock::now();
	cout << "Shell sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}