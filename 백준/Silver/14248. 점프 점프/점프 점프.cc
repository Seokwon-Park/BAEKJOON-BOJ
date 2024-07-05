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

	vector<int> b(n+5);
	vector<bool> v(n+5);
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	int st;
	cin >> st;
	queue<int> q;
	q.push(st);
	v[st] = true;
	int ans = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int nxt : {cur - b[cur], cur + b[cur]})
		{
			if (nxt <1 || nxt >n)continue;
			if (v[nxt]) continue;
			q.push(nxt);
			v[nxt] = true;
			ans++;
		}
	}

	cout << ans;

	return 0;
}
