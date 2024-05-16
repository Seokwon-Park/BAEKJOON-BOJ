#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

vector<int> v;

bool solve(int mid, int c)
{
	int res = 1;
	int prev = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - prev >= mid)
		{
			res++;
			prev = v[i];
		}
	}
	return res >= c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int st = 1;
	int en = INT_MAX-2;
	while (st < en)
	{
		int mid = (st + en+1) / 2;
		if (solve(mid, c))
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
	}
	
	cout << st;

	return 0;
}