#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		ll n;
		cin >> n;
		ll st = 1;
		ll en = 1e9;
		while (st < en)
		{
			ll mid = (st + en+1) / 2;
			if (mid * (mid + 1) / 2 > n)
				en = mid-1;
			else
				st = mid;
		}
		cout << st << '\n';
	}

	return 0;
}

