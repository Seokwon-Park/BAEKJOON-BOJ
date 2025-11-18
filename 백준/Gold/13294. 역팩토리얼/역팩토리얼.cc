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

//스털링 근사라는걸 이용한다고 함
//x의 자리수는 floor(log10(x)) + 1
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	if (s.size() <= 18)
	{
		ll n = stoll(s);
		ll m = 1;
		ll k = 0;
		while (m != n)
		{
			k++;
			m *= k;
		}
		cout << (k == 0? 1 : k) << '\n';
	}
	else
	{
		ll m = 0;
		double logsum = 0.0;
		while (true)
		{
			m++;
			logsum += log10(m);
			if ((int)logsum + 1 == s.size())
			{
				cout << m;
				break;
			}
		}
	}

	return 0;
}