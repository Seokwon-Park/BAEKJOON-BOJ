#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	double c;
	cin >> n >> c;
	int total = 0;
	int bed = 0;
	double cost = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		string t;
		cin >> a >> t;
		if (t == "bedroom")
			bed += a;
		total += a;
		if (t == "balcony")
			cost += (double)a / 2.0;
		else
			cost += a;
	}
	cout << fixed;
	cout.precision(6);
	cout << total << '\n' << bed << '\n' << cost*c;

	return 0;
}