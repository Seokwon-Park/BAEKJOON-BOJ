#include <bits/stdc++.h>

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
	
	int st = 420;
	int en = 1140;

	int tc;
	cin >> tc;
	int ans = 0;
	while (tc--)
	{
		string s;
		string ms;
		cin >> s >> ms;
		int m = stoi(ms);
		int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));

		if (t < en && t >= st)
		{
			if (t + m >= en)
			{
				ans += (en - t )*10 + (t + m - en)*5;
			}
			else
			{
				ans += m * 10;
			}
		}
		else
		{
			if (t+m < en && t+m>= st)
			{
				ans += (st - t) * 5 + (t + m - st) * 10;
			}
			else
				ans += m * 5;
				
		}
	}
	cout << ans;

	return 0;
}