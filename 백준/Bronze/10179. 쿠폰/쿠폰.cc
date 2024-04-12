#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		double n;
		cin >> n;
		cout << fixed;
		cout.precision(2);
		cout << '$' << n * 0.8 << '\n';
	}
	
	return 0;
}