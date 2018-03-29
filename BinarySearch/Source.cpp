#include<vector>
#include<iostream>
#include<optional>
#include <string>

class BinarySearch
{
public:
	BinarySearch() = delete;

	static std::optional<size_t> binarySearch(std::vector<int>& list, int item)
	{
		size_t low = 0;
		size_t high = list.size() - 1;

		while (low <= high) {
			size_t mid = (low + high) / 2;
			int guess = list[mid];
			if (guess == item) {
				return std::make_optional(mid);
			}
			if (guess > item) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		return std::nullopt;
	}
};



int main(int argc, char *argv[]) {

	std::vector<int> myList = { 1, 3, 5, 7, 9 };

	{
		auto searchResult = BinarySearch::binarySearch(myList, 5);

		auto value = searchResult.value();

		std::cout << value << std::endl; // 2
	}

	{
		auto searchResult = BinarySearch::binarySearch(myList, -1);

		auto has_value = searchResult.has_value();

		std::cout << std::boolalpha << has_value << std::endl; // false
	}

	return 0;
}