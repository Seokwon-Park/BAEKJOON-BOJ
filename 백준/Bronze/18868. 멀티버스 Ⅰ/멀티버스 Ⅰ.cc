#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> v[10];
vector<int> uni[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			v[i].push_back(k);
			uni[i].push_back(k);
		}
		sort(uni[i].begin(), uni[i].end());
		uni[i].erase(unique(uni[i].begin(), uni[i].end()), uni[i].end());
		for (int j = 0; j < n; j++)
		{
			v[i][j] = lower_bound(uni[i].begin(), uni[i].end(), v[i][j]) - uni[i].begin();
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (v[i] == v[j])
				ans++;
		}
	}
	cout << ans;

	return 0;
}