#include <bits/stdc++.h>

using namespace std;

unordered_map<int, pair<double, double>> um;
bool chk[105];

double calc_dist(int a, int b)
{
	double p1x = um[a].first;
	double p1y = um[a].second;
	double p2x = um[b].first;
	double p2y = um[b].second;

	return sqrt((p1x - p2x) * (p1x - p2x) + (p1y - p2y) * (p1y - p2y));

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		um[i] = make_pair(x, y);
	}


	priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;

	chk[1] = true;
	for (int i = 2; i <= n; i++)
	{
		pq.push({ calc_dist(1, i),1,i });
	}

	double answer = 0;
	int cnt = 0;
	while (cnt < n - 1)
	{
		double cost;
		int a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b]) continue;
		cnt++;
		answer += cost;
		chk[b] = true;
		for (int i = 1; i <= n; i++)
		{
			if(i == b) continue;
			if (!chk[i])
				pq.push({ calc_dist(b, i), b, i });
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}