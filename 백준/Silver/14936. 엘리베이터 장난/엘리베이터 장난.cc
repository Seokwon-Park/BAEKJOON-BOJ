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

	int c = min(n, 3);
	vector<bool> v(c, false);

	set<vector<bool>> s;
	s.insert(v);

	queue<pair<vector<bool>, int>> q;
	q.push({ v, m });

	while (!q.empty())
	{
		auto [vec, cur] = q.front();
		q.pop();
		if (cur >= n)
		{
			int nxt = cur - n;
			vector<bool> tmp = vec;
			for (int i = 0; i < tmp.size(); i++)
			{
				tmp[i] = !tmp[i];
			}
			if (s.find(tmp) == s.end())
			{
				s.insert(tmp);
				q.push({ tmp, nxt });
			}
		}
		if (cur >= (n + 1) / 2)
		{
			int nxt = cur - (n + 1) / 2;
			vector<bool> tmp = vec;
			for (int i = 0; i < tmp.size(); i += 2)
			{
				tmp[i] = !tmp[i];
			}
			if (s.find(tmp) == s.end())
			{
				s.insert(tmp);
				q.push({ tmp, nxt });
			}

		}
		if (cur >= n / 2)
		{
			int nxt = cur - n / 2;
			vector<bool> tmp = vec;
			for (int i = 1; i < tmp.size(); i += 2)
			{
				tmp[i] = !tmp[i];
			}
			if (s.find(tmp) == s.end())
			{
				s.insert(tmp);
				q.push({ tmp, nxt });
			}
		}
		if (cur >= (n - 1) / 3 + 1)
		{
			int nxt = cur - (n - 1) / 3 - 1;
			vector<bool> tmp = vec;
			for (int i = 0; i < tmp.size(); i += 3)
			{
				tmp[i] = !tmp[i];
			}
			if (s.find(tmp) == s.end())
			{
				s.insert(tmp);
				q.push({ tmp, nxt });
			}
		}
	}
	cout << s.size();


	return 0;
}