#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();

		int arr[256] = { 0 };
		int l = 0;
		int r = -1;
		int max = 0;
		while (l < s.size()) {
			if (r + 1 < s.size() && arr[s[r + 1]] == 0) {
				arr[s[++r]] = 1;
			}
			else {
				arr[s[l++]] = 0;
			}

			if (r - l + 1 > max)
				max = r - l + 1;
		}

		return max;
	}
};