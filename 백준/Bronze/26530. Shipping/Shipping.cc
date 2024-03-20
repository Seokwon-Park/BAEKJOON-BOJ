#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		double res = 0;
		for (int i = 0; i < n; i++)
		{
			string s;
			int a;
			double p;
			cin >> s >> a >> p;
			res += (double)a * p;
		}
		cout << fixed;
		cout.precision(2);
		cout << '$' << res << '\n';
	}

	return 0;
}