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

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int total = m * k;
	sort(v.begin(), v.end(), greater<int>());

	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		cur += v[i];
		if (cur >= total)
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << "STRESS";
	return 0;
}
