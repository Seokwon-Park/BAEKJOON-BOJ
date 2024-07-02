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
	int t = 1;
	int dir = 1;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int m;
		cin >> m;
		bool hit = (m == t);
		bool reverse = (s == "HOURGLASS");
		if (hit && reverse)
		{
			cout << t << " NO";
		}
		else if (hit)
		{
			cout << t << " YES";
		}
		else if(reverse)
		{
			cout << t << " NO";
			dir = -dir;
		}
		else
		{
			cout << t << " NO";
		}
		t += dir;
		if (t < 1)
			t += 12;
		if (t > 12)
			t -= 12;
		cout << '\n';
	}

	return 0;
}