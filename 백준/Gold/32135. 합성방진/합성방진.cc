#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	v.push_back(3);
	for (int i = 0; i < (n+1) / 2; i++)
	{
		if (i * 2 + 1 == 1 || i * 2 + 1 == 3) continue;
		v.push_back(i*2+1);
	}
	v.push_back(1);
	v.push_back(8);
	for (int i = 0; i < n / 2; i ++)
	{
		if(i*2+2 == 8 || i*2+2 == 6) continue;
		v.push_back(i*2+2);
	}
	v.push_back(6);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[(j+i) %n] << ' ';
		}
		cout << '\n';
	}

	return 0;
}