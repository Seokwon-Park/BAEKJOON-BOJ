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

	int tc;
	cin >> tc;
	while (tc--)
	{
		ll n;
		cin >> n;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			ll candy;
			cin >> candy;
			sum += (candy % n);
			sum %= n;
		}
		if (sum % n == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}