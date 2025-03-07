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
	cin >> n;
	int cura = 0;
	int curb = 0;
	bool ans = true;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a >= cura && b >= curb)
		{
			cura = a;
			curb = b;
		}
		else
		{
			ans = false;
		}
	}

	cout << (ans ? "yes":"no");

	return 0;
}