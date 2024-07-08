#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int v[11];
int n;

int func(int a, int b, int c)
{
	int res = 0;
	int aa = 1;
	int bb = 1;
	int cc = 1;
	int dd = 1;
	for (int i = 0; i <= a; i++)
	{
		aa *= v[i];
	}
	for (int j = a + 1; j <= b; j++)
	{
		bb *= v[j];
	}
	for (int k = b + 1; k <= c; k++)
	{
		cc *= v[k];

	}
	for (int l = c + 1; l < n; l++)
	{
		dd *= v[l];
	}
	return aa + bb + cc + dd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ans = -1;
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 1; j < n - 2; j++)
		{
			for (int k = j + 1; k < n - 1; k++)
			{
				ans = max(ans, func(i, j, k));
			}

		}
	}
	cout << ans;

	return 0;
}