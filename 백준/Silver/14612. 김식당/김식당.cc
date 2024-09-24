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
	
	int n, m;
	cin >> n >> m;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "order")
		{
			int table, t;
			cin >> table >> t;
			v.push_back({ table, t });
		}
		else if (cmd == "sort")
		{
			sort(v.begin(), v.end(), [](auto a, auto b)
				{
					if (a.second == b.second)
					{
						return a.first < b.first;
					}
					return a.second < b.second;
				}
			);
		}
		else
		{
			int tn;
			cin >> tn;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].first == tn)
				{
					v.erase(v.begin() + i);
				}
			}
		}

		if (v.empty())
		{
			cout << "sleep";
		}
		else
		{
			for (auto [tn, t] : v)
			{
				cout << tn << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}

