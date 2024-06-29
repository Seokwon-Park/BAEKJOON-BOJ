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

	int tc = 1;
	while (1)
	{
		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)break;
		cout << "Triangle #" << tc++ << '\n';
		cout << fixed << setprecision(3);
		if (a == -1)
		{
			

			if ((c * c - b * b) <= 0.0)
				cout << "Impossible.";
			else
				cout << "a = " << sqrt(c * c - b * b);
		}
		else if (b == -1)
		{
			
			if ((c * c - a * a) <= 0.0)
				cout << "Impossible.";
			else
				cout << "b = " << sqrt(c * c - a * a);
		}
		else
		{
			cout << "c = ";
			cout << sqrt(a * a + b * b);
		}
		cout << "\n\n";
	}

	return 0;
}