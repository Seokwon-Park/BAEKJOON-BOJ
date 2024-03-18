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

	int n;
	cin >> n;
	while (n--)
	{
		double d;
		string s;
		cin >> d >> s;
		cout << fixed;
		cout.precision(4);
		if (s == "kg")
		{
			cout << d * 2.2046 << " lb\n";
		}
		else if (s == "lb")
		{
			cout << d * 0.4536 << " kg\n";
		}
		else if (s == "l")
		{
			cout << d * 0.2642 << " g\n";
		}
		else
		{
			cout << d * 3.7854 << " l\n";
		}

	}

	return 0;
}
