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

	while (1)
	{
		int s;
		cin >> s;
		if (s == 0) break;
		cout << s << ' ';
		while (s >= 10)
		{
			int tmp = s;
			s = 1;
			while (tmp)
			{
				s *= tmp % 10;
				tmp /= 10;
			}
			cout << s << ' ';
		}
		cout << '\n';
	}


	return 0;
}