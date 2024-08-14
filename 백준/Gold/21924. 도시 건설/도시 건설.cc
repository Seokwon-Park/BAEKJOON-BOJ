#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> p(100005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void Union(int a, int b)
{
	if (a < b) p[b] = a;
	else p[a] = b;
}
bool isDiff(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	Union(a, b);
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<tuple<ll,ll,ll>> v;
	ll total = 0;
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		v.push_back(tie(c, a, b));
		total += c;
	}
	
	//Kruskal
	sort(v.begin(), v.end());

	int cnt = 0;
	ll cost = 0;
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		tie(c, a, b) = v[i];
		if (isDiff(a, b))
		{
			cost += c;
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}

	if (cnt == n - 1)
		cout << total - cost;
	else
		cout << -1;
	

	return 0;
}