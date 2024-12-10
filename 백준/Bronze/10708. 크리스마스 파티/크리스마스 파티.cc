#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}
	vector<int> score(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k;
			cin >> k;
			if (k == v[i])
			{
				score[j]++;
			}
			else
			{
				score[v[i] - 1]++;
			}
		}
	}

	for (auto i : score)
	{
		cout << i << '\n';
	}

	return 0;
}