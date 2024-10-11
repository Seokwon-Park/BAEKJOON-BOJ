#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<ll> quest(n);
	for (auto& i : quest)
		cin >> i;

	//가장 경험치 적게주는퀘스트 부터 받아서 돌부터 활성화 한다.
	sort(quest.begin(), quest.end());
	int curActive = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += curActive * quest[i];
		curActive = min(k, curActive + 1);
	}

	cout << ans;
	
	return 0;
}

