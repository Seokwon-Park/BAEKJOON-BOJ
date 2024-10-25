#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int Calc(int x)
{
	return x * (x + 1) / 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 0)
	{
		cout << Calc(n / 2 - 1) * 2;
	}
	else
	{
		cout << Calc(n / 2 - 1) + Calc(n / 2);
	}



	return 0;
}