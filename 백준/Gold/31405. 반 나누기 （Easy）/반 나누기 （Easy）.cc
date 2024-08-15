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
	vector<pair<double,double>> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}

	vector<double> pfsum(n + 1, 0.0);
	vector<double> area(n + 1, 0.0);

	for (int i = 2; i <= n - 1; i++) // 1, i, i+1로 삼각형 구성
	{
		auto [x1, y1] = v[1];
		auto [xi, yi] = v[i];
		auto [xj, yj] = v[i + 1];

		area[i] = abs((x1 * yi + xi * yj + xj * y1) - (xi * y1 + xj * yi + x1 * yj)) / 2; // 외적 삼각형 넓이 계산
		pfsum[i] = pfsum[i - 1] + area[i];
	}

	int ix = 2; // 현재 정점(삼각형) 순서
	while (pfsum[ix] < (pfsum[n - 1] / 2.0)) // 누적된 삼각형 넓이의 합이 전체 넓이의 절반보다 크거나 같은 정점 순서를 구한다.
	{
		ix++;
	}

	double tmp = pfsum[n - 1] / 2 - pfsum[ix - 1]; // 전체 넓이의 절반에서 (ix - 1)까지 포함된 삼각형을 제외한다.
	double tmp2 = area[ix]; // ix번째 삼각형의 넓이
	double t = tmp / tmp2; // ix번째 삼각형의 넓이에서 차지하는 비율을 구함.

	//cout << pfsum[n - 1] / 2 << ' ' << pfsum[ix - 1] + area[ix] * t << '\n';
	cout << "YES\n";
	cout << "1 0\n"; // 1번 정점으로 고정
	cout << ix << ' ' << fixed << setprecision(10) << t;


	return 0;
}