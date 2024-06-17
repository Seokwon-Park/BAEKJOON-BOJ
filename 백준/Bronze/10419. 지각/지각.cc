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
		
	int tc;
	cin >> tc;
	while (tc--)
	{
		int d;
		cin >> d;
		int t = 0;
		while (t + t * t <= d)
		{
			t++;
		}
		cout << t-1 << '\n';
	}

	return 0;
}
