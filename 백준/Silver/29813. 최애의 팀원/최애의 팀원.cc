#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

unordered_map<string, vector<string>> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	queue<pair<string, int>> q;
	for (int i = 0; i < n; i++)
	{
		string a;
		int b;
		cin >> a >> b;
		q.push({ a,b });
	}
	
	while (q.size() != 1)
	{
		auto [name, x] = q.front();
		q.pop();
		for (int i = 0; i < x - 1; i++)
		{
			auto tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		q.pop();
	}

	cout << q.front().first;


	return 0;
}
