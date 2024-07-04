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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string a, b;
		cin >> a >> b;

		int azero = 0;
		int bzero = 0;
		int diff = 0;
		int ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])diff++;
			azero += (a[i] == '0');
			bzero += (b[i] == '0');
		}

		if (azero != bzero)
		{
			ans += abs(azero - bzero);
			diff -= abs(azero - bzero);
		}
		ans += diff / 2;

		cout << ans << '\n';

	}


	return 0;
}
