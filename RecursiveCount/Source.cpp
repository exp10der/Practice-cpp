#include<functional>
#include<vector>
#include<iostream>

int main(int argc, char *argv[]) {

	std::function<int(std::vector<int> &)> count = [&](std::vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;

		arr.pop_back();

		return 1 + count(arr);
	};

	{
		auto list = std::vector<int>{ 1, 2, 3, 4, 5 };

		auto result = count(list);

		std::cout << result << std::endl; // 5
	}

	{
		auto list = std::vector<int>{ };

		auto result = count(list);

		std::cout << result << std::endl; // 0
	}

	return 0;
}