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

	int n;
	cin >> n;
	vector<int> v(n, 0);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		m[v[i]] = i;
	}

	int mx = *max_element(v.begin(), v.end());

	vector<int> ans(n, 0);
	for (int i = 0; i < v.size(); i++)
	{
		int tmp = v[i];
		while (tmp <= mx)
		{
			tmp += v[i];
			if (m.find(tmp) != m.end())
			{
				ans[i]++;
				ans[m[tmp]]--;
			}
		}
	}

	for (auto i : ans)
	{
		cout << i << ' ';
	}




	return 0;
}