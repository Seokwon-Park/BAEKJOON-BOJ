#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	vector<int> tt(1005);
	for (int i = 0; i < n; i++)
	{
		int s, t, b;
		cin >> s >> t >> b;
		for (int j = s; j <=t ; j++)
		{
			tt[j] += b;
		}
	}

	cout << *max_element(tt.begin(), tt.end());

	return 0;
}
