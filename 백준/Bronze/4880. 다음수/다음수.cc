#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	while (1)
	{
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		if (a1 == 0 && a2 == 0 && a3 == 0)break;
		if (a2 - a1 == a3 - a2)
		{
			cout << "AP " << a3+ (a2 - a1);
		}
		else if (a2 / a1 == a3 / a2)
		{
			cout << "GP " << a3 * (a2 / a1);
		}
		cout << '\n';
	}

	return 0;
}