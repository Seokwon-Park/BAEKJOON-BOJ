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

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "NO";
		return 0;
	}
	while (n)
	{
		int m = n % 3;
		if (m == 2)
		{
			cout << "NO";
			return 0;
		}
		n /= 3;
	}
	cout << "YES";


	return 0;
}