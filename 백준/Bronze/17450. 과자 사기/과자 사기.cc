#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

double v[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> p(3);
	vector<int> w(3);
	priority_queue<pair<double, int>> pq;
	string s = "SNU";
	for (int i = 0; i < 3; i++)
	{
		cin >> p[i] >> w[i];
		if (p[i] * 10 >= 5000)
		{
			pq.push({ (double)(w[i] * 10) / (p[i] * 10 - 500), i });
		}
		else
		{
			pq.push({ (double)(w[i] * 10) / (p[i] * 10), i});
		}
	}
	cout << s[pq.top().second];
	
	
	


	return 0;
}