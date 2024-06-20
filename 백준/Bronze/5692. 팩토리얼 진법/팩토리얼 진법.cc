#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int f[6];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i <= 5; i++)
	{
		f[i] = f[i - 1] * i;
	}


	while (1)
	{
		string n;
		cin >> n;
		if (n == "0") break;
		int  res = 0;
		for (int i = n.size(); i >= 1; i--)
		{
			int m = n[n.size()-i] - '0';
			res += m * f[i];
		}
		cout << res << '\n';
	}

	return 0;
}