#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void cocktail_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();
	size_t left = 0;
	size_t right = array.size() - 1;

	while(left < right) {
		for(size_t i = left; i < right; i++)
			if(array[i + 1] < array[i])
				swap(array[i], array[i + 1]);
		right--;

		for(size_t i = right; i > left; i--)
			if(array[i - 1] > array[i])
				swap(array[i - 1], array[i]);
		left++;
	}

	auto timer_end = chrono::steady_clock::now();
	cout << "Cocktail sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}