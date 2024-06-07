#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m;
int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 1)
				v.push_back({ i,j });
		}
	}

	cout << abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second);

	
	return 0;
}
