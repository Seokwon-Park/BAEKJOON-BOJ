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

	int n, m;
	cin >> n >> m;
	vector<bool> isLeftCrashed(n, false);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		fill(isLeftCrashed.begin() + l, isLeftCrashed.begin() + r, true);
	}

	int cnt = count(isLeftCrashed.begin()+1, isLeftCrashed.end(), false);
	cout << cnt + 1;

	return 0;
}
