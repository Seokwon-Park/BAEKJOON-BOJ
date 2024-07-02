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

	int n;
	cin >> n;

	if (n % 2 == 0)
		cout << "I LOVE CBNU";
	else
	{
		cout << string(n, '*') << '\n';
		for (int i = 0; i < n/2 +1; i++)
		{
			cout << string(n/2 - i, ' ');
			if(i == 0)
				cout << '*';
			else
			{
				cout << '*';
				cout << string((i-1) * 2 + 1, ' ');
				cout << '*';
			}
			cout << '\n';
		}

	}
	

	return 0;
}
