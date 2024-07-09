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
	
	double m, n, a;
	cin >> m >> n >> a;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double k;
		cin >> k;
		sum += k;
	}

	if (a == 1000)
	{
		cout << "Impossible";
	}
	else
	{
		cout << (m + sum) * a / (1000.0 - a);
	}



	return 0;
}