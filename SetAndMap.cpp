/*#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

//349. Intersection of Two Arrays	
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> s(nums1.begin(), nums1.end());

	set<int> r;
	for (int i = 0; i < nums2.size(); i++) {
		if (s.find(nums2[i]) != s.end()) {
			r.insert(nums2[i]);
		}
	}

	return vector<int>(r.begin(), r.end());
}

//350. Intersection of Two Arrays II
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums1.size(); i++) {
		if (m.find(nums1[i]) != m.end()) {
			m.insert(make_pair(nums1[i], 1));
		}
		else {
			m[nums1[i]]++;
		}
	}

	vector<int> result;
	for (int i = 0; i < nums2.size(); i++) {
		if (m.find(nums2[i]) != m.end()) {
			if (m[nums2[i]] > 0){
				result.push_back(nums2[i]);
				m[nums2[i]]--;
			}
		}
	}

	return result;
}

//242. Valid Anagram
bool isAnagram(string s, string t) {
	int s_size = s.size();int t_size = t.size();
	if (s_size != t_size) {
		return false;
	}

	unordered_map<char,int> map;
	for (int i = 0; i < s_size; i++) {
		map[s[i]]++;
	}

	for (int i = 0; i < t_size; i++) {
		map[t[i]]--;
		if (map[t[i]] < 0) {
			return false;
		}
	}
	return true;
}

//202. Happy Number
bool isHappy(int n) {
	unordered_set<int> set;
	int quotient = n;;
	int yushu;

	while (true) {
		int sum = 0;
		while (quotient != 0) {
			yushu = quotient % 10;
			quotient /= 10;
			sum += yushu * yushu;
		}
		if (sum == 1)
			return true;
		if (set.find(sum) != set.end()) {
			return false;
		}
		else {
			set.insert(sum);
			quotient = sum;
		}
	}
}

//290. Word Pattern
vector<string> spilt(string s) {
	vector<string> v;

	int start = 0;
	for (int i = start + 1;i <= s.size();) {
		if (i == s.size() || s[i] == ' ') {
			v.push_back(s.substr(start, i - start));
			start = i + 1;
			i = start + 1;
		}
		else
			i++;
	}
	return v;
}
bool wordPattern(string pattern, string str) {
	vector<string> s = spilt(str);
	if (pattern.size() != s.size())
		return false;

	unordered_map<char, string> map1;
	unordered_map<string, char> map2;

	for (int i = 0; i < pattern.size(); i++) {
		if (map1.find(pattern[i]) == map1.end()) {
			if (map2.find(s[i]) != map2.end())
				return false;
			map1.insert(make_pair(pattern[i], s[i]));
			map2.insert(make_pair(s[i], pattern[i]));
		}
		else {
			if (map1[pattern[i]] != s[i]) {
				return false;
			}
		}
	}
	return true;
}


//205. Isomorphic Strings
bool isIsomorphic(string s, string t) {
	int s_size = s.size(), t_size = t.size();
	if (s_size != t_size)
		return false;

	unordered_map<char, char> map1;
	unordered_map<char, char> map2;
	for (int i = 0; i < s_size; i++) {
		if (map1.find(s[i]) == map1.end()) {
			if (map2.find(t[i]) != map2.end())
				return false;
			map1.insert(make_pair(s[i], t[i]));
			map2.insert(make_pair(t[i], s[i]));
		}
		else {
			if (map1[s[i]] != t[i])
				return false;
		}
	}
	return true;
}

//451. Sort Characters By Frequency
struct record {
	char c;
	int times;
	record(char c,int times):c(c),times(times){}
};
bool operator<(const record r1, const record r2) {
	return r1.times < r2.times;
}
string frequencySort(string s) {
	int fren[256] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		fren[s[i]]++;
	}

	priority_queue<record> pq;
	for (int i = 0; i < 256; i++) {
		if (fren[i] > 0) {
			record r(i, fren[i]);
			pq.push(r);
		}
	}

	string result = "";
	while (!pq.empty()) {
		record r = pq.top();
		pq.pop();

		for (int i = 0; i < r.times; i++)
			result += r.c;
	}

	return result;
}

//387. First Unique Character in a String
int firstUniqChar(string s) {
	int fren[256] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		fren[s[i]] ++;
	}

	for (int i = 0; i < s.size(); i++) {
		if (fren[s[i]] == 1)
			return i;
	}
	return -1;
}


//1. Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	int a[2];
	for (int i = 0; i < nums.size(); i++) {
		if (map.find(target - nums[i]) == map.end()) {
			map.insert(make_pair(nums[i], i));
		}
		else {
			a[0] = map[target - nums[i]];
			a[1] = i;
			break;
		}
	}
	return vector<int>(a, a + 2);
}




int main()
{
	string s = "loveleetcode";
	cout << firstUniqChar(s) << endl;

	system("pause");
	return 0;
}*/