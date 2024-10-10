#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int n, m;
int cmp;
int ans;

void func(int k, int cur)
{
	if (k == n)
	{
		if ((cmp & cur) == cmp)
			ans++;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		func(k + 1, cur | (1 << i));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		cmp = cmp | (1 << k);
	}

	func(0, 0);

	cout << ans;

	return 0;
}

