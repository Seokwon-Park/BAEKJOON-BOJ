#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[14];
int isused[14];
int n;
int m[2700000];

void func(int k, int num)
{
	if (k == n)
	{
		if (num < 0) return;
		m[num] = true;
		return;
	}
	func(k + 1, num + v[k]);
	func(k + 1, num - v[k]);
	func(k + 1, num);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	func(0, 0);

	int ans = 0;
	for (int i = 1; i <= sum; i++)
	{
		if (!m[i])
			ans++;
	}

	cout << ans;

	return 0;
}