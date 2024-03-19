#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int t[301];

ll w(int n)
{
	ll res = 0;
	for (int k = 1; k <= n; k++)
	{
		res += (k * t[k + 1]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 301; i++)
	{
		t[i] = t[i - 1] + i;
	}
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << w(n) << '\n';
	}


	return 0;
}