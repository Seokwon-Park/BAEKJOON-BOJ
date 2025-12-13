#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//에디토리얼 : 최악의 경우 먼저 N 개의 젓가락이 하나씩 골라진 뒤, 2개 이상 남은 것들부터 2개씩 선택되고, 마지막으로 1개씩 남은 것들이 선택될 것입니다.
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	ll s = 0;
	ll p = 0;
	// N가지의 젓가락을 하나씩 뽑았다고 가정하고
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s += (v[i] - 1) / 2; //그다음 만들 수 있는 쌍
		p += (v[i] - 1) % 2; // 1개씩 뽑은 상태에서 1개를 더뽑아서 쌍을 만들 수 있는지?
	}

	if (k == 0) // 만들어야 할 쌍이 0개인 경우
	{
		cout << 0;
		return 0;
	}

	if (k > s + p) // 최대로 쌍을 뽑아도 k쌍을 만들 수 없는 경우
	{
		cout << -1;
	}

	else if (k <= s)
	{
		//1개씩 뽑아놓은 경우 n
		//여기서 1개만 뽑으면 1쌍이 완성되지만 최악을 고려하면 1개를 남기고 한쌍이 되어야 하므로 k개의 쌍을 완성시킬때마다 사실상 2개씩 뽑는것
		//근데 마지막은 1개뽑으면 끝이기 때문에 2개를 뽑을 필요가 없음
		cout << n + 2 * k - 1;
	}
	else if (k > s)
	{
		//1개씩 뽑아놓은 경우 n
		//만들 수 있느 쌍을 다 만든 경우 2*s
		//남은 목표 짝 개수: K - s
		cout << n + 2 * s + (k - s);
	}




	return 0;
}