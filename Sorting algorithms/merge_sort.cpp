#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void sorting(vector<int> &array);

void merge_sort(vector<int> v) {
	auto timer_begin = chrono::steady_clock::now();

	sorting(v);

	auto timer_end = chrono::steady_clock::now();
	cout << "Merge sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}

void sorting(vector<int> &array) {
	size_t size = array.size();
	if (size == 1)
		return;

	size_t middle = size / 2;

	vector<int> left(begin(array), begin(array) + middle);
	vector<int> right(begin(array) + middle, end(array));

	sorting(left);
	sorting(right);

	size_t l = 0;
	size_t r = 0;

	for(int i = 0; i < size; i++) {
		if(l == left.size()) {
			for(; i < size; i++)
				array[i] = right[r++];
			break;
		}

		if(r == right.size()) {
			for(; i < size; i++)
				array[i] = left[l++];
			break;
		}

		array[i] = left[l] <= right[r] ? left[l++] : right[r++];
	}
}