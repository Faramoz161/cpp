#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void sorting(vector<int>::iterator left, vector<int>::iterator right);

void quick_sort(vector<int> array) {
	auto timer_begin = chrono::steady_clock::now();

	sorting(begin(array), end(array));

	auto timer_end = chrono::steady_clock::now();
	cout << "Quick sort: " << chrono::duration_cast<chrono::milliseconds>(timer_end - timer_begin).count() << "\n";
}

void sorting(vector<int>::iterator begin, vector<int>::iterator end) {
	if(end - begin <= 1)
		return;

	int middle = *(begin + (end - begin) / 2);
	auto i = begin;
	auto j = end - 1;
	
	while(i <= j) {
		while(*i < middle)
			i++;
		while(*j > middle)
			j--;

		if (i <= j) {
			swap(*i, *j);
			i++;
			j--;
		}
	}

	if(begin < j) sorting(begin, j + 1);
	if(i < end) sorting(i, end);
}