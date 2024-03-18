#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a1, p1;
	double r1, p2;
	cin >> a1 >> p1;
	cin >> r1 >> p2;
	double a = a1 / p1;
	double b = r1 * r1 * PI / p2;

	if (a > b)
	{
		cout << "Slice of pizza";
	}
	else
	{
		cout << "Whole pizza";
	}

	return 0;
}