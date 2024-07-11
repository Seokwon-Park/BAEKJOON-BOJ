#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, r;
	cin >> n >> r;
	// 최악의 경우 종류별 n번 1번씩 뽑음 -> 그다음에 뽑는 애는 무조건 짝이 맞춰져서 +1 
	// 그리고 나서 최악의 경우가 되려면 짝이맞춰진 색깔과 같은 색을 2번 뽑는 경우가 최악의 경우
	// 따라서 n+1 + 2*(r-1) = n+2*r-1 이다. ㄷㄷ;
	cout << n - 1LL + 2LL * r;


	return 0;
}
