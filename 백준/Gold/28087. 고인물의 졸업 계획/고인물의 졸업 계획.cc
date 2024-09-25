#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int v[5000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	ll s = 0;
	vector<int> ans;
	for (int i = 1; i <= m; i++)
	{
		cin >> v[i];
		if (v[i] >= n && v[i] <= n * 2)
		{
			cout << 1 << '\n' << i << '\n';
			return 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (v[i] < n)
		{
			s += v[i];
			ans.push_back(i);
		}
		if (s >= n)
		{
			break;
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << '\n';

	return 0;
}

