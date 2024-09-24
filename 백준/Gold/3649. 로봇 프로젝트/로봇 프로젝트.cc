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

	int x;
	while (cin >> x)
	{
		int nano = x * 10'000'000;
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int st = 0;
		int en = n-1;
		bool isFind = false;
		while (st < en)
		{
			if (v[st] + v[en] == nano)
			{
				cout << "yes " << v[st] << ' ' << v[en] << '\n';
				isFind = true;
				break;
			}
			else if (v[st] + v[en] > nano)
			{
				en--;
			}
			else
			{
				st++;
			}
		}
		if (!isFind)
		{
			cout << "danger\n";
		}
	}

	return 0;
}

