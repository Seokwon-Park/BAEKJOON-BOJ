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

	string p = "2023";

	int ans = 0;
	for (int i = 2023; i <= n; i++)
	{
		string s = to_string(i);
		int j = 0;
		for (auto c : s)
		{
			if (c == p[j]) j++;
			if (j == p.size())
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;

	

	return 0;
}
