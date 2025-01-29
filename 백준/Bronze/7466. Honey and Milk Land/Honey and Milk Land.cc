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
	
	int n, e;
	cin >> n >> e;

	double x;

	double nn = 0.0;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x;
		nn += x;
	}

	double ee = 0.0;
	for (int i = 0; i < e - 1; i++)
	{
		cin >> x;
		ee += x;
	}

	cout << ceil(sqrt(nn * nn + ee * ee));

	return 0;
}