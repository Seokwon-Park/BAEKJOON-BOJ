//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int d, c;
		cin >> d >> c;
		v.push_back({ d,c });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
		{
			pq.pop();
		}
	}

	int ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;


	return 0;
}