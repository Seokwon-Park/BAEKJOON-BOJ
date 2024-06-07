#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a = 1;
	int b = 1;

	int ans = 0;
	while (a <= 500 && b <= a)
	{
		if (a * a - b * b == n)
		{
			ans++;
			b++;
		}
		else if (a * a - b * b < n)
		{
			a++;
		}
		else
		{
			b++;
		}
	}

	cout << ans;


	return 0;
}
