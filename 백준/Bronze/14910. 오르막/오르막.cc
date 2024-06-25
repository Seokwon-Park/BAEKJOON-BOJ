#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int last = INF;
	while (cin >> n)
	{
		if (last == INF)
			last = n;
		else if (last > n)
		{
			cout << "Bad";
			return 0;
		}
		else
		{
			last = n;
		}
	}
	cout << "Good";

	return 0;
}