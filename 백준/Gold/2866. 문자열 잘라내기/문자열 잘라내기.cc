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
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	vector<string> v(r);
	for (int i = 0; i < r; i++)
	{
		cin >> v[i];
	}

	vector<string> h(c);
	for (int i = r-1; i >= 0; i--)
	{
		for (int j = 0; j < c; j++)
		{
			h[j].push_back(v[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < r-1; i++)
	{
		set<string> s;
		for (int j = 0; j < c; j++)
		{
			h[j].pop_back();
			s.insert(h[j]);
		}
		if (s.size() == c)cnt++;
		else break;
	}

	cout << cnt;

	return 0;
}