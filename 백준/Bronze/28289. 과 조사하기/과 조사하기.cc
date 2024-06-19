#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int p;
	cin >> p;

	vector<int> m(3, 0);
	int fm = 0;

	for (int i = 0; i < p; i++)
	{
		int g, c, n;
		cin >> g >> c >> n;

		if (g == 1)
		{
			fm++;
		}
		else
		{
			if (c <= 2) m[0]++;
			else if (c <= 3) m[1]++;
			else m[2]++;
		}
	}

	for (auto i : m)
		cout << i << '\n';
	cout << fm;
	

	return 0;
}