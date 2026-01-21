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

	vector<int> ans;
	ans.reserve(n);

	int st = 1;
	int en = n;
	for (int i = 0; i < n; i++)
	{
		if (n - i - 1 <= m)
		{
			m -= n - i - 1;
			ans.push_back(en);
			en--;
		}
		else
		{
			ans.push_back(st);
			st++;
		}
	}

	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}