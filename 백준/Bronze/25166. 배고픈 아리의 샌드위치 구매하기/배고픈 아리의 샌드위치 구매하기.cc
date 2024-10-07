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

	int n, m;
	cin >> n >> m;
	if (n < 1024)
		cout << "No thanks";
	else
	{
		int toBurrow = n - 1023;
		while (toBurrow)
		{
			int a = toBurrow % 2;
			int b = m % 2;
			if (a == 1)
			{
				if (b == 0)
				{
					cout << "Impossible";
					return 0;
				}
			}
			toBurrow >>= 1;
			m >>= 1;
		}
		cout << "Thanks";
	}


	return 0;
}