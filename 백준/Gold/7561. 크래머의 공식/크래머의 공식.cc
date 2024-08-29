#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll det(vector<vector<ll>>& a)
{
	return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
		- a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
		+ a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

void swapCol(vector<vector<ll>>& v, int a, int b)
{
	for (int i = 0; i < 3; i++)
	{
		swap(v[i][a], v[i][b]);
	}
}

double check(double x)
{
	if (x <0.0005 && x >-0.0005)
		return 0.0;
	else
		return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<vector<ll>> v(3, vector<ll>(4, 0));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> v[i][j];
			}
		}

		ll detA = det(v);
		swapCol(v, 0, 3);
		ll detA1 = det(v);
		swapCol(v, 0, 3);
		swapCol(v, 1, 3);
		ll detA2 = det(v);
		swapCol(v, 1, 3);
		swapCol(v, 2, 3);
		ll detA3 = det(v);
		cout << detA1 << ' ' << detA2 << ' ' << detA3 << ' ' << detA << '\n';
		if (detA == 0)
		{
			cout << "No unique solution";
		}
		else
		{
			double x1 = (double)detA1 / detA;
			double x2 = (double)detA2 / detA;
			double x3 = (double)detA3 / detA;
			x1 = check(x1);
			x2 = check(x2);
			x3 = check(x3);
			cout << "Unique solution: ";
			cout << fixed << setprecision(3) << x1 << ' ' << x2 << ' ' << x3;
		}
		cout << "\n\n";
	}

	return 0;
}