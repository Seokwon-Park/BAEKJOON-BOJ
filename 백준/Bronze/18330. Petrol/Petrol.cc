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

	int n, k;
	cin >> n >> k;
	int inb = k + 60;
	if (n <= inb)
	{
		cout << 1500 * n;
	}
	else
	{
		cout << 1500 * inb + 3000 * (n - inb);
	}

	return 0;
}

