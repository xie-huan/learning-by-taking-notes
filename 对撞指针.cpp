#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

//167. Two Sum II - Input array is sorted
vector<int> twoSum(vector<int>& numbers, int target) {
	int l = 0;
	int r = numbers.size() - 1;
	vector<int> result;

	while (l < r) {
		int sum = numbers[l] + numbers[r];
		if (sum < target)
			l++;
		else if (sum > target)
			r--;
		else {
			result.push_back(l);
			result.push_back(r);
			return result;
		}
	}
	return result;
}

//125. Valid Palindrome
bool isAlphanumeric(char a) {
	if (a >= 'a' && a <= 'z')
		return true;
	if (a >= 'A' && a <= 'Z')
		return true;
	if (a >= '0' && a <= '9')
		return true;
	return false;
}
bool isPalindrome(string s) {
	//将字符串的不相关符号去掉
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isAlphanumeric(s[i])) {
			s[index] = s[i];
			index++;
		}
	}
	//将字符串转换成小写
	for (int i = 0; i < index; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] + ('a' - 'A');
		}
	}

	int l = 0; 
	int r = index-1;
	while (l < r) {
		if (s[l] != s[r])
			return false;
		else {
			l++;
			r--;
		}
	}
	return true;
}

//344. Reverse String
void reverseString(vector<char>& s) {
	
	int l = 0; 
	int r = s.size() - 1;

	while (l < r) {
		swap(s[l], s[r]);
		l++;r--;
	}
}

//345. Reverse Vowels of a String
bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
		return true;
	}
	return false;
}
string reverseVowels(string s) {
	vector<int> record;
	for (int i = 0; i < s.size(); i++) {
		if (isVowel(s[i])) {
			record.push_back(i);//记录是元音的下标
		}
	}

	int l = 0; 
	int r = record.size() - 1;

	while (l < r) {
		swap(s[record[l]], s[record[r]]);
		l++;
		r--;
	}
	return s;
}

//11. Container With Most Water
int maxArea(vector<int>& height) {
	int l = 0;
	int r = height.size() - 1;
	
	int maxAreaResult = 0;
	while (l < r) {
		int minHeight = 0;
		int minIndex = 0;
		int maxIndex = 0;
		if (height[l] < height[r]) {
			minHeight = height[l];
			minIndex = l;
			maxIndex = r;
		}
		else {
			minHeight = height[r];
			minIndex = r;
			maxIndex = l;
		}

		int temp = minHeight * (r - l);
		maxAreaResult = maxAreaResult>temp?maxAreaResult: temp;

		if (maxIndex == r) {
			for (int i = l + 1; i < maxIndex;i++) {
				int tempMinHeight = min(height[i], height[r]);
				int tempMaxArea = tempMinHeight * (r - i);
				if (tempMaxArea > maxAreaResult)
					maxAreaResult = tempMaxArea;
			}
		}
		else if(maxIndex == l){
			for (int i = r - 1; i > maxIndex;i--) {
				int tempMinHeight = min(height[l], height[i]);
				int tempMaxArea = tempMinHeight * (i - l);
				if (tempMaxArea > maxAreaResult)
					maxAreaResult = tempMaxArea;
			}
		}
		l++;
		r--;
	}
	return maxAreaResult;
}

//168. Excel Sheet Column Title
string numToChar(int n) {
	char a = n + 65;
	char c[2] = { a };
	return c;
}
string convertToTitle(int n) {
	string result = "";
	int a = n-1, b;
	stack<string> s;
	bool flag = false;
	if (n == 1)
		return "A";
	while (a != 0) {
		b = a % 26;
		if(!flag)
			s.push(numToChar(b));
		a = a / 26;
		if (a != 0){
			a--;
			if (a < 26) {
				s.push(numToChar(a));
				flag = true;
			}
		}
	}
	while (!s.empty()) {
		string temp = s.top();
		s.pop();
		result += temp;
	}
	return result;
}
/*int main()
{
	int a[] = { 2,3,10,5,7,8,9 };
	//int a[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	int c = maxArea(v);
	cout << c << endl;
	system("pause");
	return 0;
}*/