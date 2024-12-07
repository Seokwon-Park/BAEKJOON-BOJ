#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int pow(int n, int exp)
{
	int ret = 1;
	for (int i = 0; i < exp; i++)
	{
		ret *= n;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int a, b;
		a = m / 10;
		b = m % 10;
		x += pow(a, b);
	}
	cout << x;
	
	return 0;
}