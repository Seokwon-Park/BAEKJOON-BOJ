#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

vi t(1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	sort(v.begin(), v.end());
	int prev = -1005;
	for (int i : v)
	{
		if (i != prev)
		{
			cout << i << ' ';
			prev = i;
		}
	}

	

	return 0;
}