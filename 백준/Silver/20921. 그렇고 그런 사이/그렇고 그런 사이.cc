#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<bool> use(n+1);
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > 0; j--)
		{
			if (use[j]) continue;
			if (j - 1 <= m)
			{
				m -= j - 1;
				ans.push_back(j);
				use[j] = true;
				break;
			}
		}
	}

	for(int i = 1; i<=n;i++)
	{
		if (use[i]) continue;
		ans.push_back(i);

	}

	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}
