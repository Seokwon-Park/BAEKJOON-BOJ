#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

double a, b, c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;

	//a+b = d1;
	//a+c = d2;
	//b+c = d3;

	//a - c = d1 - d2;
	//2a = d1-d2+d3

	int twoa = d1 - d3+d2;
	if (twoa <= 0)
	{
		cout << -1;
	}
	else
	{
		a = twoa / 2.0;
		b = d1 - a;
		if (b <= 0)
		{
			cout << -1;
		}
		else
		{
			c = d2 - a;
			if (c <= 0)
			{
				cout << -1;
			}
			else
			{
				cout << 1 << '\n';
				cout << fixed << setprecision(1);
				cout << a << ' ' << b << ' ' << c;
			}
		}

	}



	
	return 0;
}



