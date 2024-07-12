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
	string s;
	cin >> s;
	int isReadyForR = 0;
	int isReadyForK = 0;
	int ans = 0;
	for (auto c : s)
	{
		if (c <= '9' && c >= '1')
		{
			ans++;
		}
		else if (c == 'L')
			isReadyForR++;
		else if (c == 'S')
			isReadyForK++;
		else if (c == 'R')
		{
			if (isReadyForR > 0)
			{
				isReadyForR--;
				ans++;
			}
			else
			{
				break;
			}
		}
		else if (c == 'K')
		{
			if (isReadyForK > 0)
			{
				isReadyForK--;
				ans++;
			}
			else
			{
				break;
			}
		}
	}
	cout << ans;

	return 0;
}