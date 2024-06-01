#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b && a > c)
			swap(a, c);
		else if (b > a && b > c)
			swap(b, c);

		cout << "Scenario #" << i << ":\n";
		if (c * c == a * a + b * b)
			cout << "yes";
		else
			cout << "no";
		
		cout << "\n\n";
	}

	return 0;
}