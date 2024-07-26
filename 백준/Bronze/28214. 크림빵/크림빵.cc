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

	int n, k, p;
	cin >> n >> k >> p;

	vector<int> v(n * k);
	for (int i = 0; i < n * k; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n * k; i += k)
	{
		int noCream = count(v.begin() + i, v.begin() + i + k, 0);
		if (noCream < p)
			ans++;
	}
	cout << ans;


	return 0;
}