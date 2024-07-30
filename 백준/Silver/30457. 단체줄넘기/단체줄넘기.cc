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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> front;
	vector<int> back;

	for (int i = 0; i < n; i++)
	{
		if (front.empty())
			front.push_back(v[i]);
		else if (front.back() < v[i])
			front.push_back(v[i]);
		else if (back.empty())
			back.push_back(v[i]);
		else if (back.back() < v[i])
			back.push_back(v[i]);
	}

	cout << front.size() + back.size();

	return 0;
}