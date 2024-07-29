#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

double q[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n <= 4)
	{
		cout << 4;
		return 0;
	}

	int a = 1;
	int b = 1;
	bool flag = false;
	while (1)
	{
		if (a * b >= n)
		{
			cout << (a-1) * 2 + (b-1) * 2;
			return 0;
		}
		if (flag)
			a++;
		else
			b++;
		flag = !flag;
	}

	return 0;
}