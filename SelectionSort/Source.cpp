#include<vector>
#include<iostream>

class SelectionSort
{
public:
	SelectionSort() = delete;

	static std::vector<int> selectionSort(std::vector<int>& list) {
		size_t size = list.size();

		auto newList = std::vector<int>();
		newList.reserve(list.size());

		for (size_t i = 0; i < size; i++) {
			size_t smallest = findSmallest(list);
			newList.push_back(list[smallest]);

			list.erase(list.begin() + smallest);
		}

		return newList;
	}

	static size_t findSmallest(const std::vector<int>& list) {
		int smallest = list[0];
		size_t smallestIndex = 0;
		for (size_t i = 0; i < list.size(); i++) {
			if (list[i] < smallest) {
				smallest = list[i];
				smallestIndex = i;
			}
		}
		return smallestIndex;
	}
};



int main(int argc, char *argv[]) {

	std::vector<int> myList = { 7, 3, 6, 2, 10 };
	
	auto result = SelectionSort::selectionSort(myList);

	for (const auto& item : result) //[2, 3, 6, 7, 10]
		std::cout << item << ' ';

	return 0;
}