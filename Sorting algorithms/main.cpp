#include "main.h"

int main() {
	const size_t size = 10000000;
	vector<int> array(size, 0);

	// fill
	generate(begin(array), end(array), UniqueNumber);

	// shuffle
	mt19937 g { random_device {}() };
	g.seed(time(NULL));
	shuffle(begin(array), end(array), g);

	bubble_sort(array);
	//cocktail_sort(array);
	//comb_sort(array);
	//insertion_sort(array);
	//shell_sort(array);
	//selection_sort(array);
	//tree_sort(array);
	//merge_sort(array);
	//radixLSD_sort(array);
	//quick_sort(array);

	system("pause");
	return 0;
}