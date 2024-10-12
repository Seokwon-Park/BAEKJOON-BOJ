#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, d, k;
	cin >> a >> d >> k;
	if ((k - a) % d != 0)
	{
		cout << 'X';
	}
	else
	{
		int i = (k - a) / d;
		if (i + 1 <= 0)
		{
			cout << 'X';
		}
		else
		{
			cout << i + 1;
		}
	}




	return 0;
}
