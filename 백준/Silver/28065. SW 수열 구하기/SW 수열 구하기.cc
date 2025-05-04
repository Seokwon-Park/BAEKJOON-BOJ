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
	int st = 1;
	int en = n;

	for (int i = n; i > 0; i--)
	{
		if (i % 2 == 0)
		{
			cout << en--;
		}
		else
		{
			cout << st++;
		}
		cout << ' ';
	}
	
	
	return 0;
}
