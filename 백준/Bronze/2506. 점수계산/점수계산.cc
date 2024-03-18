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
	vi v(n);
	for (auto& i : v)
	{
		cin >> i;
	}

	int cont = 0;
	int prev = 0;
	int total = 0;
	for (auto i : v)
	{
		if(i == 1)
		{
			if (prev == 1)
			{
				total += cont;
			}
			total++;
			cont++;
			prev = 1;
		}
		else
		{
			prev = 0;
			cont = 0;
		}
	}
	cout << total;

	return 0;
}