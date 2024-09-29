#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	int onionGood = 1;
	int onionBad = 1;
	for (int i = 0; i < n; i++)
	{
		onionGood += a;
		onionBad += b;
		if (onionGood < onionBad)
		{
			swap(onionGood, onionBad);
		}
		else if (onionGood == onionBad)
		{
			onionBad--;
		}
	}
	cout << onionGood << ' ' << onionBad;

	return 0;
}