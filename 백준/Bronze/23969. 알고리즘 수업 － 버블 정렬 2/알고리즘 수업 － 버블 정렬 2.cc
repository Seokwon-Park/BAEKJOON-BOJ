#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int tmp;

void b_sort(vector<int>& a, int& k)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		for(int j = 0; j< i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp++;
				swap(a[j], a[j + 1]);
				if (tmp == k)
				{
					for (auto m : a)
						cout << m << ' ';
					exit(0);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	b_sort(v, k);

	cout << -1;

	return 0;
}