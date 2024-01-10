#include <bits/stdc++.h>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first > b.first;
		
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	multiset<pair<int,int>, cmp> ms;
	map<int, int> mm;
	for (int i = 0; i < n; i++)
	{
		int q, diff;
		cin >> q >> diff;
		ms.insert({ diff, q });
		mm.insert({ q, diff });
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string op;
		cin >> op;
		if (op == "add")
		{
			int q, diff;
			cin >> q >> diff;
			ms.insert({ diff, q });
		}
		else if (op == "recommend")
		{
			int x;
			cin >> x;
			if (x == -1)
			{
				cout << prev(ms.end())->second << '\n';
			}
			else
			{
				cout << ms.begin()->second << '\n';
			}
		}
		else
		{
			int x;
			cin >> x;
			int diff = mm[x];
			ms.erase({diff, x});
		}
	}

	//for (auto m : ms)
	//{
	//	cout << m.first << ' ' << m.second << '\n';
	//}

	return 0;
}
