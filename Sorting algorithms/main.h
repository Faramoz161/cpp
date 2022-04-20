#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

// generator unique number (0, 1, 2, ...):
struct unique_number {
	int current;
	unique_number() {
		current = 0;
	}
	int operator()() {
		return current++;
	}
} UniqueNumber;

void bubble_sort(vector<int> array);
void cocktail_sort(vector<int> array);
void insertion_sort(vector<int> array);
void selection_sort(vector<int> array);
void comb_sort(vector<int> array);
void merge_sort(vector<int> array);
void radixLSD_sort(vector<int> array);
void shell_sort(vector<int> array);
void quick_sort(vector<int> array);
void tree_sort(vector<int> array);