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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int tmp = n;
		int pow = 1;
		while (tmp)
		{
			tmp /= 10;
			pow *= 10;
		}

		if ((n * n) % pow == n)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}