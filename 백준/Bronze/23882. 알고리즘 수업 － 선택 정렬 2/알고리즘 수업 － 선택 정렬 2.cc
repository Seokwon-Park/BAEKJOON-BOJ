#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, k;
int swapped;

void my_sort(vector<int>& a)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		int ix = max_element(a.begin(), a.begin() + i + 1)- a.begin();
		if (i != ix)
		{
			swap(a[i], a[ix]);
			swapped++;
			if (k == swapped)
			{
				for (int i : a)
					cout << i << ' ';
				exit(0);
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	my_sort(a);

	cout << -1;

	return 0;
}