#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int v[10005];
int swapped = 0;
int ans = -1;
int ans2 = -1;

int part(int* v, int p, int r, int k)
{
	int x = v[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (v[j] < x)
		{
			swap(v[++i], v[j]);
			swapped++;
			if (swapped == k)
			{
				ans = i;
				ans2 = j;
				return -1;
			}
		}
	}
	if (i + 1 != r)
	{
		swap(v[i + 1], v[r]);
		swapped++;
		if (swapped == k)
		{
			ans = i+1;
			ans2 = r;
			return -1;
		}
	}
	return i + 1;
}

void quick(int* v, int p, int r, int k)
{
	if (p < r)
	{
		int q = part(v, p, r, k);
		if (q == -1) return;
		quick(v, p, q - 1, k);
		quick(v, q + 1, r, k);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	quick(v, 0, n - 1, k);

	if (ans == -1)
	{
		cout << ans;
	}
	else
	{

		cout << v[ans] << ' ' << v[ans2];
	}



	return 0;
}