#include<iostream>
#include<vector>
using namespace std;

//704. Binary Search
int search(vector<int>& nums, int target) {

	int l = 0;
	int r = nums.size()-1;

	while (l <= r) {
		//avoid overflow here
		int mid = l + (r - l) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int main() {

	return 0;
}