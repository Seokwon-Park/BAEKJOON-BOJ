#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

void printBox(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int i = 0; i < c; i++)
		{
			cout << '@';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	printBox(n, n * 5);
	printBox(n*3, n);
	printBox(n, n * 5);

	return 0;
}