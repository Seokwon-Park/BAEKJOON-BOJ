#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	vector<ll> pfsum(n + 1, 0);
	set<int> nums;

	// 어떤 숫자의 맨 처음과 맨 끝 위치만 기록함.
	// why?? 이게 그 숫자로 만들 수 있는 최대 합이기 때문에
	// 근데 ai의 범위가 10^9까지기 때문에 이걸 배열로는 못 만들고 map을 쓴다.
	map<ll, int> max_ix;
	map<ll, int> min_ix;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		pfsum[i] = pfsum[i - 1] + v[i];
		max_ix[v[i]] = i;
		if (min_ix.find(v[i]) == min_ix.end())
		{
			min_ix[v[i]] = i;
		}
		nums.insert(v[i]);
	}

	map<ll, int> m;
	ll max_value = 0;
	for (int i : nums)
	{
		ll res = pfsum[max_ix[i]] - pfsum[min_ix[i] - 1];
		max_value = max(max_value, res);
		m[res]++;
	}

	cout << max_value << ' ' << m[max_value];

	return 0;
}
