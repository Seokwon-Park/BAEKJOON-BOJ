#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, s;
	cin >> a >> b >> s;

	int l = max(a, b);
	while (1)
	{
		int res = (l - a) * (l - b);
		if (res == s)
		{
			cout << l;
			break;
		}
		else if (res > s)
		{
			cout << -1;
			break;
		}
		l++;
	}


	return 0;
}