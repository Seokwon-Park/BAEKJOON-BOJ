#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int tri[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	sort(t.begin(), t.end(), greater<int>());

	for (int i = 1; i <= t.size(); i++)
	{
		t[i - 1] += i;
	}

	cout << *max_element(t.begin(), t.end())+1;

	return 0;
}
