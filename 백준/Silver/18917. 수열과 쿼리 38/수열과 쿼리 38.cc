#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	multiset<int> ms;
	int m;
	cin >> m;
	ll total = 0;
	ll xorres = 0;
	for (int i = 0; i < m; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int n;
			cin >> n;
			ms.insert(n);
			total += n;
			xorres ^= n;
		}
		else if (cmd == 2)
		{
			int n;
			cin >> n;
			multiset<int>::iterator itr = ms.find(n);
			ms.erase(itr);
			total -= n;
			xorres ^= n;
		}
		else if (cmd == 3)
			cout << total << '\n';
		else
			cout << xorres << '\n';
	}

	return 0;
}