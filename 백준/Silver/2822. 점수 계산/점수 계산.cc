#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= 8; i++)
	{
		int score;
		cin >> score;
		pq.push({ score, i });
	}

	int total = 0;
	vi ixs;
	for (int i = 0; i < 5; i++)
	{
		auto [score, ix] = pq.top(); pq.pop();
		ixs.push_back(ix);
		total += score;
	}
	cout << total << '\n';
	sort(ixs.begin(), ixs.end());
	for (auto i : ixs)
	{
		cout << i << ' ';
	}

	return 0;
}
