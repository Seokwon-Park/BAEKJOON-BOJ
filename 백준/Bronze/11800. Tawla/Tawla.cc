
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

map<int, string> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	m[1] = "Yakk";
	m[2] = "Doh";
	m[3] = "Seh";
	m[4] = "Ghar";
	m[5] = "Bang";
	m[6] = "Sheesh";
 
	m[11] = "Habb Yakk";
	m[22] = "Dobara";
	m[33] = "Dousa";
	m[44] = "Dorgy";
	m[55] = "Dabash";
	m[66] = "Dosh";


	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);
		cout << "Case " << i << ": ";
		if (a == 6 && b == 5)
		{
			cout << "Sheesh Beesh";
		}
		else if (a == b)
		{
			cout << m[a * 10 + b];
		}
		else
		{
			cout << m[a] << ' ' <<  m[b];
		}
		cout << '\n';

	}


	return 0;
}