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

	int tc;
	cin >> tc;
	for(int ix = 1; ix<= tc; ix++)
	{
		int b;
		double w;
		cin >> b >> w;
		double total = 0.0;
		for (int i = 0; i < b; i++)
		{
			double r;
			cin >> r;
			total += (4.0 / 3.0 * acos(-1.0) * r * r * r)/1000.0;
		}
		cout << "Data Set " << ix << ":\n";
		if (total >= w)
			cout << "Yes";
		else
			cout << "No";
		cout << "\n\n";
	}

	return 0;
}
