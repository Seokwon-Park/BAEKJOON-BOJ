#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	int draw = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		res += x;
		if (x == 0)draw++;
	}
	if (draw >= (n + 1) / 2)
	{
		cout << "INVALID";
	}
	else if (res <= 0)
	{
		cout << "REJECTED";
	}
	else
	{
		cout << "APPROVED";
	}

	return 0;
}