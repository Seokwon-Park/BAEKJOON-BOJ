#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	vector<int> p1(n + 1);
	vector<int> p2(n + 1);
	vector<int> p3(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		p1[i] = p1[i - 1];
		p2[i] = p2[i - 1];
		p3[i] = p3[i - 1];
		if (v[i] == 1)p1[i]++;
		if (v[i] == 2)p2[i]++;
		if (v[i] == 3)p3[i]++;
	}

	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << p1[b] - p1[a - 1] << ' ' << p2[b] - p2[a - 1] << ' ' << p3[b] - p3[a - 1] << '\n';
	}

	return 0;
}