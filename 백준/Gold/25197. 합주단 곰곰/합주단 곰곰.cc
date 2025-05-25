//에디토리얼 참고
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	//합주단원의 쌍의 수
	int p = n * (n - 1) / 2;
	//그 쌍이 같은 음을 고를 확률?
	double m = 1.0 / k;

	cout << fixed << setprecision(6) << p * m;



	return 0;
}