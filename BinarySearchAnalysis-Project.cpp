#include <iostream>
#include <vector>
#include <random>

using namespace std;

int recursiveBinarySearch(const vector<int>& arr, int targ, int low, int high) {
	if (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == targ) {
			return mid;
		}
		else if (arr[mid] < targ) {
			return recursiveBinarySearch(arr, targ, mid + 1, high);
		}
		else {
			return recursiveBinarySearch(arr, targ, low, mid - 1);
		}
	}
	else {
		return -1;
	}
}

int iterativeBinarySearch(const vector<int>& arr, int targ) {
	int low = 0;
	int high = arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == targ) {
			return mid;
		}
		else if (arr[mid] < targ) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int sequentialSearch(vector<int>& arr, int targ) {
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == targ) {
			return i;
		}
	}
	return -1;
}

int main() {
	vector<int> nums;

	mt19937 rng(random_device{}());

	uniform_int_distribution<int> distribution(1, 100);

	for (int i = 0; i < 10; ++i) {
		nums.push_back(distribution(rng));
	}
	for (int i = 0; i < 10; ++i) {
		std::cout << nums[i] << " ";
	}

	int target;

	std::cout << "\n" << endl;

	std::cout << target << endl;
	

	return 0;
}