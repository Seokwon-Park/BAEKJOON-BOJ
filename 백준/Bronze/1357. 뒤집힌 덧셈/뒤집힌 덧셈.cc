#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;

int rev(int n)
{
	int tmp = n;
	int rv = 0;
	while (tmp)
	{
		rv = rv * 10 + tmp % 10;
		tmp /= 10;
	}
	return rv;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;
	cout << rev(rev(x) + rev(y));

	return 0;
}