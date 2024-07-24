#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n, m;
pii v[100];
vector<bool> xi(1, false);
bool f = false;

void func(int k)
{
	if (k > n)
	{
		bool res = 1;
		for (int i = 0; i < m; i++)
		{
			auto [a, b] = v[i];
			if (a > 0 && b > 0)
				res &= xi[a] || xi[b];
			else if (a > 0 && b < 0)
				res &= xi[a] || (!xi[-b]);
			else if (a < 0 && b > 0)
				res &= (!xi[-a]) || xi[b];
			else if (a < 0 && b < 0)
				res &= (!xi[-a]) || (!xi[-b]);
			if (!res)return;
		}
		f |= res;
		if (f)
		{
			cout << 1 << '\n';
			for (int i = 1; i<= n; i++)
				cout << xi[i] << ' ';
			exit(0);
		}
		return;
	}

	xi.push_back(0);
	func(k+1);
	xi.pop_back();
	xi.push_back(1);
	func(k+1);
	xi.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	func(1);

	cout << 0;
	
	return 0;
}