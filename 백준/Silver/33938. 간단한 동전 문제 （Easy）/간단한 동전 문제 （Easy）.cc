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

	int n, m;
	cin >> n >> m;

	vector<int> coin(n);
	for (int& i : coin)cin >> i;

	map<int, bool> v;
	queue<int> q;
	q.push(0);
	v[0] = 1;
	int ans = 0;
	
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front();
			q.pop();
			if (cur == m)
			{
				cout << ans;
				exit(0);
			}
			for (int cost : coin)
			{
				int nxt = cur + cost;
				if (nxt < -1000 || nxt >1000 || v[nxt])continue;
				q.push(nxt);
				v[nxt] = true;
			}
		}
		ans++;
	}
	cout << -1;

	return 0;
}