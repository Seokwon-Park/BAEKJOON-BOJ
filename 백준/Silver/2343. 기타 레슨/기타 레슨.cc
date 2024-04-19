#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, m;
int v[100005];

bool solve(int mid)
{
	int left = mid;
	int cd = 1;
	for (int i = 0; i < n; i++)
	{
 		if (mid < v[i]) return false;
		if (left >= v[i])
		{
			left -= v[i];
		}
		else
		{
			cd++;
			left = mid - v[i];
		}
	}
	return cd <= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i< n; i++)
		cin >> v[i];

	int st = 1;
	int en = INT_MAX-1;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid+1;
		}
	}
	cout << st;

	return 0;
}