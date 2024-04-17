#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
int v[12];
int op[4];
int res;
int mx = INT_MIN;
int mn = INT_MAX;

void func(int k, int res)
{
	if (k == n - 1)
	{
		mx = max(res, mx);
		mn = min(res, mn);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] == 0) continue;
		op[i]--;
		if(i == 0)
		{
			func(k + 1, res + v[k + 1]);
		}
		else if (i == 1)
		{
			func(k + 1, res - v[k + 1]);
		}
		else if (i == 2)
		{
			func(k + 1, res * v[k + 1]);
		}
		else
		{
			func(k + 1, res / v[k + 1]);
		}
		op[i]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}
	func(0, v[0]);

	cout << mx << '\n' << mn;

	return 0;
}
