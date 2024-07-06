//풀이 참고해서 품.
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
	
	string s;
	cin >> s;
	ll k;
	cin >> k;
	k--;
	int n = 0;

	// 1, 2, 6, 7인 자리가 몇개인지 찾는다.
	// 예제에서는 4자리
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1' || s[i] == '6')
		{
			s[i] = '1';
			n += 1;
		}
		else if (s[i] == '2' || s[i] == '7')
		{
			s[i] = '2';
			n += 1;
		}
	}
	int kk = 0;
	string b = "";
	while (k) // k = 4라면 0000, 0001, 0010, 0011해서 0011이 4번째라는 걸 알 수 있음. 0부터 시작하기때문에 
		//k를 2진법 변환전에 -1해준다.
	{
		b.push_back(k % 2LL + '0');
		k /= 2LL;
		kk++;
	}

	if (n < kk) // k를 2진법 변환햇을때 요구하는 자리수가 더 클 수 없다.
	{
		cout << -1;
		return 0;
	}
	
	b = b + string(n - b.size(), '0');


	int j = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '1') // 2진법 변환한 값이 1이라면 1대신 6으로 변환해준다.
		{
			if (b[j] == '1')
				s[i] = '6';
			j++;
		}
		else if (s[i] == '2')
		{
			if (b[j] == '1')
				s[i] = '7';
			j++;
		}
	}
	cout << s;

	return 0;
}