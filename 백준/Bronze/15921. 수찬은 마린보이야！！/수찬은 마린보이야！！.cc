#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

map<double, double> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double n;
	cin >> n;
	if (n == 0)
	{
		cout << "divide by zero";
		return 0;
	}
	double total = 0.0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		d[m]++;
		total += m;
	}

	double avg = total / n;
	double avg2 = 0;
	for (auto [x, y] : d)
	{
		avg2 += x * (y / n);
	}

	cout << fixed << setprecision(2);
	cout << avg / avg2;


	return 0;
}