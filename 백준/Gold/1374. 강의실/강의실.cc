#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tiii> v;
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int ix, st, en;
		cin >> ix >> st >> en;
		v.push_back(tie(st, en, ix));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		int ix, st, en;
		tie(st, en, ix) = v[i];
		if (pq.empty())
		{
			pq.push(tie(en, st, ix));
		}
		else
		{
			int enn, stt, ixx;
			tie(enn, stt, ixx) = pq.top();
			if (enn <= st)
			{
				pq.pop();
			}
			pq.push(tie(en, st, ix));
		}
	}

	ans = max(ans, (int)pq.size());
	cout << ans;

	return 0;
}