#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		bool isPow = true;
		while (a != 1)
		{
			if (a & 1)
			{
				isPow = false;
				break;
			}
			a >>= 1;
		}
		if (isPow)
			cout << 1;
		else
			cout << 0;
		cout << '\n';
	}


	return 0; 
}