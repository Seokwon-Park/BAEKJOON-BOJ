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
	
	int n, a, b;
	cin >> n >> a >> b;
	int s, t;
	cin >> s >> t;
	if (s > a && s<b && t > a && t < b)
	{
		cout << "City";
	}
	else if((s <=a && t <=a) || (s>=b && t >=b))
	{
		cout << "Outside";
	}
	else
	{
		cout << "Full";
	}

	return 0;
}