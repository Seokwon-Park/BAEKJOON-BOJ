#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int v[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<pii> ans;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == i) continue;
		for (int j = i + 1; j <= n; j++)
		{
			if (v[j] == i)
			{
				ans.push_back({ i, j });
				reverse(v + i, v + j+1);
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto [a, b] : ans)
		cout << a << ' ' << b << '\n';


	return 0;
}