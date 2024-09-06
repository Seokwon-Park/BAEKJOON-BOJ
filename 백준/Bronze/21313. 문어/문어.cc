#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ans(n, 1);
	for (int i = 1; i < n; i += 2)
	{
		ans[i] = 2;
	}
	if (n % 2 == 1)
		ans[n - 1] = 3;

	for (auto i : ans)
		cout << i << ' ';
	
	return 0;
}