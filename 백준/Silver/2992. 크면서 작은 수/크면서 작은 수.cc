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
	
	int x;
	cin >> x;

	string c = to_string(x);
	sort(c.begin(), c.end());
	int ans = INT_MAX;
	do
	{
		int cmp = stoi(c);
		if (x < cmp)
		{
			ans = min(ans, cmp);
		}
	} while (next_permutation(c.begin(), c.end()));
	cout << (ans == INT_MAX? 0: ans);

	return 0;
}
