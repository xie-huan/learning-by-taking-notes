#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

//209. Minimum Size Subarray Sum
int minSubArrayLen(int s, vector<int>& nums) {
	int sum = 0;
	int result = nums.size();
	int l = 0;
	int r = -1;

	int size = nums.size();
	while (l < size) {
		if (r < size - 1 && sum < s)
			sum += nums[++r];
		else
			sum -= nums[l++];

		if (sum >= s)
			result = min(result, r - l + 1);
	}
	return result;
}

//3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
	int fren[256] = { 0 };
	int l = 0;
	int r = -1;
	int result = 0;

	while (l < s.size()) {
		//注意这里的判断条件不能写成r<s.size()-1
		//因为s.size()返回为size_type，为无符号数，r初始为负数
		//比较时会将r转换成无符号数，-1对应的无符号数非常大
		//所以导致无法进入if
		if (r + 1 < s.size() && fren[s[r + 1]] == 0) {
			r++;
			fren[s[r]]++;
		}
		else {
			fren[s[l]]--;
			l++;
		}

		result = max(result, r - l + 1);
	}
	return result;
}

//438. Find All Anagrams in a String
vector<int> findAnagrams(string s, string p) {
	vector<int> result;
	if (p.size() > s.size()) {
		return result;
	}
	if (p == s){
		result.push_back(0);
		return result;
	}

	int fren[256] = { 0 };
	for (int i = 0; i < p.size(); i++) {
		fren[p[i]]++;
	}
	
	int l = 0;
	int r = -1;
	while (l < s.size()) {
		if (r + 1 < s.size() && fren[s[r+1]] >= 1) {
			fren[s[++r]]--;
		}
		else
			fren[s[l++]]++;
		
		if (r - l + 1 == p.size())
			result.push_back(l);
	}

	return result;
}

//76. Minimum Window Substring
string minWindow(string s, string t) {
	string result = "";
	if (t.size() > t.size())
		return result;
	if (s == t)
		return s;

	//Too Hard For Me...
	//See https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
	//for solution
}


/*int main()
{
	int a[] = { 2,3,1,2,4,3 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	int x = minSubArrayLen(7, v);
	cout << x << endl;

	system("pause");
	return 0;
}*/