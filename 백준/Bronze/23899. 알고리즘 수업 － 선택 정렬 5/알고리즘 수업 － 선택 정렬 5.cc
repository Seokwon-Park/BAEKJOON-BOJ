#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> cmp;

int selection_sort(vector<int>& v)
{
	if (v == cmp)
		return 1;
	for (int i = v.size() - 1; i >= 1; i--)
	{
		int ix = max_element(v.begin(), v.begin()+i+1) - v.begin();
		if (i != ix)
		{
			swap(v[i], v[ix]);
		}
		if (v == cmp)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	cmp.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cmp[i];
	}

	cout << selection_sort(v);

	return 0;
}