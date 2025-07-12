#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	while (cin >> s)
	{
		istringstream iss(s);
		string tmp;
		int n;
		while (getline(iss, tmp, '/'))
		{
			n = stoi(tmp);
		}
		int ans = 0;
		for (int i = 1; i * i <= n * n; i++)
		{
			if (n*n % i == 0)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}