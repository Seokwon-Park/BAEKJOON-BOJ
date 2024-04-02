#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<double, vector<double>, greater<double>> pq;
	for (int i = 0; i < n; i++)
	{
		double m;
		cin >> m;
		pq.push(m);
	}
	
	for(int i = 0; i<7;i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}
