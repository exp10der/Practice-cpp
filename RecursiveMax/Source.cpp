#include<functional>
#include<vector> 
#include<iostream>

int main(int argc, char *argv[]) {

	std::function<int(std::vector<int> &)> max = [&](std::vector<int>& arr)
	{
		if (arr.size() == 1)
			return arr[0];

		auto item = arr.back();
		arr.pop_back();

		auto resulFn = max(arr);

		return item > resulFn ? item : resulFn;
	};

	auto list = std::vector<int>{ 1, 2, 3, 4, 5 };

	auto result = max(list);

	std::cout << result << std::endl; // 5

	return 0;
}