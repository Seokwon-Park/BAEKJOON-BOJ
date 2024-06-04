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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << "Pairs for " << n << ": ";
		for (int i = 1; i <= n/2; i++)
		{
			if (n - i == i) continue;
			if (i != 1)
				cout << ", ";
			cout << i << ' ' << n - i;
		}
		cout << '\n';
	}

	return 0;
}