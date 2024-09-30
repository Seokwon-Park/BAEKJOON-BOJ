#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


//애드혹
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int st = 1;
	// 모든 값이 홀수로 구성되어 있으면 합은 짝수 곱은 홀수가 되기때문에 조건을 무조건 만족함.
	for(ll i = 0; i< n;i++)
	{
		cout << st << ' ';
		st += 2;
	}


	return 0;
}

