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
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		int st = 1;
		int en = 50;
		while (1)
		{
			int mid = (st + en) / 2;
			cout << mid << ' ';
			if (mid == n)
			{
				break;
			}
			else if(mid < n)
			{
				st = mid + 1;
			}
			else
			{
				en = mid - 1;
			}
		}
		cout << '\n';
	}


	return 0;
}