#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<int> last(105, 1005);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<int, int> list;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (list.size() < n)
		{
			if (list.find(k) == list.end())
			{
				last[k] = i;
			}
			list[k]++;
		}
		else
		{
			if (list.find(k) != list.end())
			{
				list[k]++;
			}
			else
			{
				int mn = min_element(list.begin(), list.end(), [=](const auto& a, const auto& b) 
					{
						if (a.second == b.second)
						{
							return last[a.first] < last[b.first];
						}
						return a.second < b.second;
					})->first;
				list.erase(mn);
				last[k] = i;
				list[k]++;
			}
		}
	}

	for (auto [a, b] : list)
	{
		cout << a << ' ';
	}

	return 0;
}