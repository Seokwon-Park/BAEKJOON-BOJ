#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;



void mysort(int st, int en, vector<int>& v)
{
	int l = st;
	int mid = (st+en) / 2;
	int r = mid;
	vector<int> tmp;
	while (l < mid && r < en)
	{
		if (v[l] <= v[r])
			tmp.push_back(v[l++]);
		else
			tmp.push_back(v[r++]);
	}
	while (l < mid)tmp.push_back(v[l++]);
	while (r < en)tmp.push_back(v[r++]);
	for (int i = 0; i < en-st ; i++)
	{
		v[st + i] = tmp[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int k;
	cin >> k;
	
	int p = n;
	while (p != k)
	{
		p /= 2;
		for (int i = 0; i < n; i += n / p)
		{
			mysort(i, i + n / p, v);
		}
	}

	for (int i : v)
		cout << i << ' ';

	return 0;
}