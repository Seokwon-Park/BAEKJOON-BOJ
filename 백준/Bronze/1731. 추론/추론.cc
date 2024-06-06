#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a, ad;
	cin >> a >> ad;
	int prev = ad;
	int gap = ad -a;
	bool flag = false;
	for (int i = 0; i < n-2; i++)
	{
		int v;
		cin >> v;
		if (!flag && gap != v - prev)
		{
			flag = true;
			gap = v / prev;
		}
		prev = v;
	}
	if (flag)
		cout << prev * gap;
	else
		cout << prev + gap;

	return 0;
}