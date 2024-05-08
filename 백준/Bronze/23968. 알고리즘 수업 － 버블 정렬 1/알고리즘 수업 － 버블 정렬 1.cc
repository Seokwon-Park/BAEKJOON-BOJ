#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int swapped = 0;

void bubble_sort(vector<int>& v, const int& k)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j + 1])
			{
				swapped++;
				swap(v[j], v[j + 1]);
				if (swapped == k)
				{
					cout << v[j] << ' ' << v[j + 1];
					return;
				}
			}
		}
	}
	cout << -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for (auto& i : v)
	{
		cin >> i;
	}

	bubble_sort(v, k);

	return 0;
}