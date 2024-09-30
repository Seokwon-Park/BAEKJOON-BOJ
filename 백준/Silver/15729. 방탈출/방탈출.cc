#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<bool> v(n);
	vector<bool> cur(n, false);
	for (int i = 0; i < n; i++)
	{
		bool b;
		cin >> b;
		v[i] = b;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] != cur[i])
		{
			cur[i] = !cur[i];
			if (i + 1 < n)
			{
				cur[i + 1] = !cur[i + 1];
			}
			if (i + 2 < n)
			{
				cur[i + 2] = !cur[i + 2];
			}
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}

