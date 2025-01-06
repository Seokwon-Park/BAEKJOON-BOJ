#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	bool isyt = true;
	while (1)
	{
		if (a >= 5 || b >= 5) break;
		if (isyt)
		{
			b += a;
		}
		else
		{
			a += b;
		}
		isyt = !isyt;
	}

	if (a >= 5)
	{
		cout << "yj";
	}
	else
	{
		cout << "yt";
	}

	return 0;
}