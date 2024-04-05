#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k;
string nums[11];
unordered_map<string, bool> um;
bool isused[11];

void func(int m, string s)
{
	if (m == k)
	{
		um[s] = true;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isused[i]) continue;
		isused[i] = true;
		func(m + 1, s + nums[i]);
		isused[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	func(0, "");

	cout << um.size();

	return 0;
}