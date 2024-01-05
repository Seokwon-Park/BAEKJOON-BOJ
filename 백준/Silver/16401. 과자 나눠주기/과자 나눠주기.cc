#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<int> cookies(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cookies[i];
	}

	int st = 0;
	int ed = INT_MAX-1;

	int mid;
	while (st < ed)
	{
		int res = 0;
		mid = (st + ed+1) / 2;
		for (auto cookie : cookies)
		{
			res += cookie / mid;
		}
		if (m <= res) 
		{
			st = mid;
		}
		else
		{
			ed = mid-1;
		}
	}

	cout << st;

	return 0;
}