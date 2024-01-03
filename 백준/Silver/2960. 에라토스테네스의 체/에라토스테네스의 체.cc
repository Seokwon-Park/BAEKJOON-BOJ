#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<bool> nums(n + 5, false);

	int delcount = 0;
	int val = 0;
	for (int i = 2; i <= n; i++)
	{
		if (nums[i] == true) continue;
		for (int j = i; j <= n; j += i)
		{
			if (nums[j] == true) continue;
			nums[j] = true;
			delcount++;
			if (delcount == k)
			{
				val = j;
				break;
			}
		}
	}

	cout << val;

	return 0;
}