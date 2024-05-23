#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int a[105][105];
int curr = 3;
int curc = 3;
int r, c, k;

vector<int> line(vector<int>& v)
{
	vector<pii> tmp;
	vector<int> ret;
	for (int i = 1; i <= 100; i++)
	{
		if (v[i] != 0)
			tmp.push_back({ v[i], i });
	}
	sort(tmp.begin(), tmp.end());

	for (auto [a, b] : tmp)
	{
		ret.emplace_back(b);
		ret.emplace_back(a);
	}
	return ret;
}

void rcalc()
{
	int mx = curc;
	for (int i = 0; i < curr; i++)
	{
		vector<int> v(101);
		for (int j = 0; j < curc; j++)
		{
			if(a[i][j] != 0)
				v[a[i][j]]++;
		}
		vector<int> res = line(v);
		while (res.size() < curc) res.push_back(0);
		for (int j = 0; j< res.size(); j++)
		{
			a[i][j] = res[j];
		}
		mx = max(mx, (int)res.size());
	}
	curc = mx;
}

void ccalc()
{
	int mx = curr;
	for (int i = 0; i < curc; i++)
	{
		vector<int> v(101);
		for (int j = 0; j < curc; j++)
		{
			if (a[j][i] != 0)
				v[a[j][i]]++;
		}
		vector<int> res = line(v);
		while (res.size() < curr) res.push_back(0);
		for (int j = 0; j < res.size(); j++)
		{
			a[j][i] = res[j];
		}
		mx = max(mx, (int)res.size());
	}
	curr = mx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> k;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}

	int t = 0;
	while (t <= 100)
	{
		if (a[r - 1][c - 1] == k)
		{
			cout << t;
			return 0;
		}
		if (curr >= curc)
			rcalc();
		else
			ccalc();
		t++;

		//cout << '\n';
		//for (int i = 0; i < curr; i++)
		//{
		//	for (int j = 0; j < curc; j++)
		//	{
		//		cout << a[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	}

	cout << -1;
	return 0;
}