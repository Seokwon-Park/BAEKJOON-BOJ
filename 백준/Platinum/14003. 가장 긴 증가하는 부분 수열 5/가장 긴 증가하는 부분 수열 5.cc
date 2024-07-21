#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

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
	vector<int> arr;
	vector<int> ix(n);
	for (int i = 0; i < n; i++)
	{
		if (arr.empty() || arr[arr.size() - 1] < v[i])
		{
			arr.push_back(v[i]);
			ix[i] = arr.size() - 1;
		}
		else
		{
			int lb = lower_bound(arr.begin(), arr.end(), v[i]) - arr.begin();
			arr[lb] = v[i];
			ix[i] = lb;
		}
	}

	cout << arr.size() << '\n';
	int j = arr.size()-1;
	vector<int> ans;
	for (int i = v.size()-1; i >= 0; i--)
	{
		if (ix[i] == j)
		{
			ans.push_back(v[i]);
			j--;
		}
	}

	while (!ans.empty())
	{
		cout << ans.back() << ' ';
		ans.pop_back();
	}

	return 0;
}