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

	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	vi res;
	while (q.size()>1)
	{
		int fr = q.front();
		q.pop();
		res.push_back(fr);
		fr = q.front();
		q.pop();
		q.push(fr);
	}

	for (auto i : res)
	{
		cout << i << ' ';
	}
	cout << q.front();

	return 0;
}