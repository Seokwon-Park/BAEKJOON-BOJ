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

	int pizza = 1;
	while (1)
	{
		double r, w, l;
		cin >> r >> w >> l;
		if (r == 0) break;
		double a = r * 2;
		double b = sqrt(w * w + l * l);
		cout << "Pizza " << pizza++;
		if (a >= b)
			cout << " fits on the table.";
		else
			cout << " does not fit on the table.";
		cout << '\n';
	}

	return 0;
}