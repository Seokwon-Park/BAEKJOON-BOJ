#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n;
int v[500005];

int bfs(vector<int> houses)
{
	queue<int> q;
	for (int i = 0; i < houses.size(); i++)
	{
		q.push(houses[i]);
		v[houses[i]] = 1;
	}

	int res = 0;
	int d = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			int cur = q.front();
			q.pop();
			for (int i = -1; i <= 1; i += 2)
			{
				int nxt = cur + i;
				if (nxt < 0 || nxt >= n || v[nxt])continue;
				res += d;
				q.push(nxt);
				v[nxt] = 1;
			}
		}
		d++;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		fill(v, v + n, 0);
		vector<int> h;
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			if (c == '1')
			{
				h.push_back(i);
			}
		}
		cout << "Case #" << tc << ": " << bfs(h) << '\n';
	}

	return 0;
}