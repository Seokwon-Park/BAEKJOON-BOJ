#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			v[b - 1] = c;
		}
		else if (a == 2)
		{
			for (int j = b - 1; j < c; j++)
			{
				v[j] = v[j] == 1 ? 0 : 1;
			}
		}
		else if (a == 3)
		{
			fill(v.begin() + b - 1, v.begin() + c, 0);
		}
		else 
			fill(v.begin() + b - 1, v.begin() + c, 1);
	}

	for (auto i : v)
		cout << i << ' ';

	return 0;
}
