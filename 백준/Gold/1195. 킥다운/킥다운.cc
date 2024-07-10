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
	
	string a, b;
	cin >> a >> b;

	if (a.size() < b.size())
		swap(a, b);

	int n = a.size(); 
	int m = b.size();
	int ans = n + m;
	for (int i = -m+1; i < n; i++)
	{
		bool isKick = true;
		for (int j = 0; j < m; j++)
		{
			if (i + j >= n || i+j <0 )continue;
			if (b[j] == '2' && a[i + j] == '2')
			{
				isKick = false;
				break;
			}
		}
		if (isKick)
		{
			if (i < 0)
			{
				ans = min(ans, -i + n);
			}
			else if (i + m <= n)
			{
				ans = min(ans, n);
			}
			else if (i + m > n)
			{
				ans = min(ans, i + m);
			}
		}
	}
	cout << ans;

	return 0;
}