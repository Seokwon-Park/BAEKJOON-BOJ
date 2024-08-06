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
	
	string s;
	cin >> s;

	int u = 0;
	int dp = 0;
	for (auto c : s)
	{
		if (c == 'U' || c == 'C')
			u++;
		else if (c == 'D' || c== 'P')
		{
			dp++;
		}
	}
	
	if (u > dp / 2 + (dp % 2 == 0 ? 0 : 1))
		cout << "U";
	if(dp >0)
		cout << "DP";


	return 0;
}