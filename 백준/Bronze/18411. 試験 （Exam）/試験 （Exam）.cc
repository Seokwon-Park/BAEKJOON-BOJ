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

	vi v(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	cout << v[1] + v[2];


	return 0;
}