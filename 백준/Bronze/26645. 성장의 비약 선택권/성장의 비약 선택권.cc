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
	if (n < 206)
	{
		cout << 1;
	}
	else if (n < 218)
	{
		cout << 2;
	}
	else if (n < 229)
	{
		cout << 3;
	}
	else
	{
		cout << 4;
	}

	return 0;
}



