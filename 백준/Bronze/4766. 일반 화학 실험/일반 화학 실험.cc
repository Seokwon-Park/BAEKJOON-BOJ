#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double prev;
	cin >> prev;
	while (1)
	{
		double n;
		cin >> n;
		if (n == 999.0)break;
		cout << fixed << setprecision(2);
		cout << n - prev << '\n';
		prev = n;
	}


	return 0;
}