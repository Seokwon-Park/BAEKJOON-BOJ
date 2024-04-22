#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[22];
set<int> s;
int n;

void func(int k, int m)
{
	if (k == n)
	{
		s.insert(m);
		return;
	}

	func(k + 1, m);
	func(k + 1, m + v[k]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v[i] = m;
	}
	
	func(0, 0);

	int k = 1;
	while (s.find(k) != s.end())
		k++;
	cout << k;

	return 0;
}
