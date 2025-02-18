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

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	// 0 1 2 3 4
	// add (0, val)
	// 
	// add (1, val)


	int shift = 0;
	for (int i = 0; i < q; i++)
	{
		int cmd; 
		cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			int ix;
			cin >> ix;
			ix--;
			int val;
			cin >> val;
			v[(shift+ix)%n] += val;
			break;
		}
		case 2:
		{
			int x;
			cin >> x;
			shift = (shift + (n - x)) % n;
			break;
		}
		case 3:
		{
			int x;
			cin >> x;
			shift = (shift+x)%n;
			break;
		}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << v[(i + shift) % n] << ' ';
	}


	return 0;
}
