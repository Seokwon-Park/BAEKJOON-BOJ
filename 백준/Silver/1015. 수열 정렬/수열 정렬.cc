#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	multimap<int, int> mm; //value index;

	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i ++)
	{
		cin >> nums[i];
	}

	vector<int> tmp = nums;
	sort(tmp.begin(), tmp.end());

	unordered_map<int, int> um; // value, idx;
	for (int i = 0; i < n; i++)
	{
		if (um.find(tmp[i]) != um.end())
			continue;
		um[tmp[i]] = i;
	}

	for (auto n : nums)
	{
		cout << um[n]++ << ' ';
	}
		

	return 0;
}