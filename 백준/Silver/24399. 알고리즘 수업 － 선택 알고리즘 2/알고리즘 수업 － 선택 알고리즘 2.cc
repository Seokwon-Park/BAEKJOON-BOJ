#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int swapped;
int n, q, k;

int partition(vector<int>& a, int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{
			swap(a[++i], a[j]);
			swapped++;
			if (swapped == k)
			{
				for (auto i : a)
					cout << i << ' ';
				exit(0);
			}
		}
	}
	if (i + 1 != r)
	{
		swap(a[i + 1], a[r]);
		swapped++;
		if (swapped == k)
		{
			for (auto i : a)
				cout << i << ' ';
			exit(0);
		}
	}
	return i + 1;
}

int select(vector<int>& a, int p, int r, int q)
{
	if (p == r)return a[p];
	int t = partition(a, p, r);
	int k = t - p + 1;
	if (q < k) return select(a, p, t - 1, q);
	else if (q == k) return a[t];
	else return select(a, t + 1, r, q - k);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q >> k;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	select(v, 0, n - 1, q);
	if (swapped <= k)
	{
		cout << -1;
	}

	return 0;
}