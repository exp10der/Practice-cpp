#include<functional>
#include<vector> 
#include<iostream>

int main(int argc, char *argv[]) {

	std::function<int(std::vector<int> &)> sum = [&](std::vector<int>& arr)
	{
		if (arr.size() == 1)
			return arr[0];

		auto item = arr.back();
		arr.pop_back();

		return item + sum(arr);
	};

	auto list = std::vector<int>{ 1, 2, 3, 4, 5 };

	auto result = sum(list);

	std::cout << result << std::endl; // 15

	return 0;
}