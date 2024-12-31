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

	int n;
	while (true)
	{
		cin >> n;
		if (n == -1) break;
		vector<int> v(n+1, 0);
		int result = 0;
		for (int i = 1; i <= n; i++)
		{
			int s;
			cin >> s >> v[i];
			result += s * (v[i] - v[i - 1]);
		}
		cout << result << " miles\n";
	}

	return 0;
}