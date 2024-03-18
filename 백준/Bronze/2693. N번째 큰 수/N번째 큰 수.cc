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
		vi v(10);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end(), greater<int>());
		cout << v[2] << '\n';
	}

	return 0;
}