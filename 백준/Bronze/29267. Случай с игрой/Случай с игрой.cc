#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int save = 0;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "ammo")
		{
			cur += k;
		}
		else if (cmd == "save")
		{
			save = cur;
		}
		else if (cmd == "load")
		{
			cur = save;
		}
		else
		{
			cur--;
		}
		cout << cur << '\n';
	}

	return 0;
}