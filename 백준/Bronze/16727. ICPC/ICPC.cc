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

	int p1, s1;
	int s2, p2;
	cin >> p1 >> s1;
	cin >> s2 >> p2;
	int psum = p1 + p2;
	int ssum = s1 + s2;
	if (psum > ssum)
	{
		cout << "Persepolis";
	}
	else if (psum < ssum)
	{
		cout << "Esteghlal";
	}
	else
	{
		if (s1 > p2)
		{
			cout << "Esteghlal";
		}
		else if (s1 < p2)
		{
			cout << "Persepolis";
		}
		else
		{
			cout << "Penalty";
		}
	}

	return 0;
}