#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

vector<bool> v(1<<25);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int an;
	while (cin >> an)
	{
		if (!v[an])
		{
			cout << an << ' ';
			v[an] = true;
		}
	}



	return 0;
}