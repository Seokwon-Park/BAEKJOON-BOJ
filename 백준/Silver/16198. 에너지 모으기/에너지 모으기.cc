#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[10];
bool isused[10];
int n;
int res;
int ans = INT_MIN;

void func(int sz)
{
	if (sz == 2)
	{
		ans = max(ans, res);
		return;
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (isused[i])continue;
		isused[i] = true;
		int l = 1;
		int r = 1;
		while (isused[i - l]) l++;
		while (isused[i + r]) r++;
		res += v[i - l] * v[i + r];
		func(sz - 1);
		res -= v[i - l] * v[i + r];
		isused[i] = false;
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

	func(n);

	cout << ans;

	return 0;
}
