#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

vector<int> c(1);

int func(int n)
{
	int cn = c[n];
	if (cn == 1) return n;
	if (cn % 2 == 0)
	{
		c.push_back(cn / 2);
		return func(n + 1);
	}
	else
	{
		c.push_back(3 * cn + 1);
		return func(n + 1);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	c.push_back(n);

	cout << func(1);
}
