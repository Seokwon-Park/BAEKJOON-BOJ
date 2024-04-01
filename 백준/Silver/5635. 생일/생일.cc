#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<tuple<int, int, int>, string>> v;
	while (n--)
	{
		string name;
		int dd, mm, yy;
		cin >> name >> dd >> mm >> yy;
		v.push_back({ tie(dd,mm,yy), name });
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			int add, amm, ayy;
			tie(add, amm, ayy) = a.first;
			int bdd, bmm, byy;
			tie(bdd, bmm, byy) = b.first;
			if (ayy == byy)
			{
				if (amm == bmm)
				{
					return add > bdd;
				}
				return amm > bmm;
			}
			return ayy > byy;
		});
	
	cout << v.begin()->second << '\n' << v.rbegin()->second;

	return 0;
}
