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
	
	double v, w, d;
	cin >> v >> w >> d;
	// t = w/v;

	double cur = 0;
	int ans = 0;
	double t = w / v;

	while (1)
	{
		double leftd = d - cur;
		double s = 5 * t * t;
		if (leftd > s)
		{
			cur += s;
			ans++;
		}
		else
		{
			break;
		}
		t *= 1.25;

	}
	cout << ans;


	return 0;
}
