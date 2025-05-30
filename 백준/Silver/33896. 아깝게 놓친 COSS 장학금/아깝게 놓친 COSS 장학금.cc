#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, int, string>> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		double sc, risk, cost;
		cin >> name >> sc >> risk >> cost;
		int res = sc * sc * sc / (cost * (risk + 1));
		v.push_back({ res,cost, name });
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			auto [ares, acost, aname] = a;
			auto [bres, bcost, bname] = b;
			if (ares == bres)
			{
				if (acost == bcost)
				{
					return aname < bname;
				}
				return acost < bcost;
			}
			return ares > bres;
		});

	cout << get<2>(v[1]);


	return 0;
}