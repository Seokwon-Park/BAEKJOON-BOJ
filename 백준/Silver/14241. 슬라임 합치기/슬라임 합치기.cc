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

	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		pq.push(m);
	}

	int score = 0;
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		score += a * b;
		pq.push(a + b);

	}
	cout << score;



	return 0;
}