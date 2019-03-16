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
		//ע��������ж���������д��r<s.size()-1
		//��Ϊs.size()����Ϊsize_type��Ϊ�޷�������r��ʼΪ����
		//�Ƚ�ʱ�Ὣrת�����޷�������-1��Ӧ���޷������ǳ���
		//���Ե����޷�����if
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

int main()
{
	int a[] = { 2,3,1,2,4,3 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	int x = minSubArrayLen(7, v);
	cout << x << endl;

	system("pause");
	return 0;
}