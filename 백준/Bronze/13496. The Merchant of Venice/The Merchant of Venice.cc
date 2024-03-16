#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++)
	{
		int n, s, d;
		cin >> n >> s >> d;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int di, vi;
			cin >> di >> vi;
			int eta = di / s + (di % s == 0 ? 0 : 1);
			if (eta <= d)
				res += vi;
		}
		cout << "Data Set " << t << ":\n";
		cout << res << "\n\n";

	}

	return 0;
}