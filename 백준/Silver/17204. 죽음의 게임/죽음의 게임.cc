#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool v[150];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> nxt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nxt[i];
	}

	int tell = 1;
	int cur = 0;
	while (!v[cur])
	{
		v[cur] = true;
		//speak tell
		cur = nxt[cur];
		if (cur == k)
		{
			cout << tell;
			return 0;
		}
		tell++;
	}

	cout << -1;

	return 0;
}