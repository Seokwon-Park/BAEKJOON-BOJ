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

	int a, c, e;
	int x, y, z;
	cin >> a >> c >> e;
	cin >> x >> y >> z;

	if (z >= e)
	{
		if (y >= c)
		{
			if (x >= a)
			{
				cout << 'A';
			}
			else if (x >= (a+1) / 2)
			{
				cout << 'B';
			}
			else
			{
				cout << 'C';
			}
		}
		else if (y >= (c+1) / 2)
		{
			cout << 'D';
		}
		else
		{
			cout << 'E';
		}
	}


	return 0;
}
