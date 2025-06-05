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

	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<bool> stop(a, false);
		
		for (int i = b; i < a; i += b)
		{
			stop[i] = true;
		}
		
		for (int i = c; i < a; i += c)
		{
			stop[i] = true;
		}
		
		cout << a << ' ' << b << ' ' << c << '\n';
		cout << count(stop.begin(), stop.end(), 1) << '\n';

	}

	return 0;
}