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
	while (cin >> n, n != 0)
	{
		int john = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			john += x;
		}
		cout << "Mary won " << n - john << " times and John won " << john << " times\n";
	}


	return 0;
}