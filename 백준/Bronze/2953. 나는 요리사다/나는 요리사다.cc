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
	
	vi v(5, 0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int sc;
			cin >> sc;
			v[i] += sc;
		}
	}

	int ans = INT_MIN;
	int aix = -1;
	for (int i = 0; i < 5; i++)
	{
		if (v[i] > ans)
		{
			ans = v[i];
			aix = i;
		}
	}

	cout << aix + 1 << ' ' << v[aix];


	return 0;
}

