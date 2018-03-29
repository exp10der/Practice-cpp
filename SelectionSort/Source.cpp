#include<vector>

class SelectionSort
{
public:
	SelectionSort() = delete;

	static std::vector<int> selectionSort(const std::vector<int>& list) {
		throw std::logic_error("Function not yet implemented.");
	}

	static int findSmallest(const std::vector<int>& list) {
		int smallest = list[0];
		int smallestIndex = 0;
		for (int i = 0; i < list.size(); i++) {
			if (list[i] < smallest) {
				smallest = list[i];
				smallestIndex = i;
			}
		}
		return smallestIndex;
	}
};



int main(int argc, char *argv[]) {

	std::vector<int> myList = { 1, 3, 5, 7, 9 };


	return 0;
}