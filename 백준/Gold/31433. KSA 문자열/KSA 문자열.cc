#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string ksa;
	cin >> ksa;

	int len = ksa.length();
	int curlen = len;

	string p = "KSA";
	int pt = 0;

	int k = 0, s = 0, a = 0;

	for (int i = 0; i < ksa.length(); i++)
	{
		if (ksa[i] == p[pt])
		{
			pt = (pt + 1) % 3;
		}
		else
		{
			k++;
			curlen--; //현재 길이를 지운다.
		}
	}
	k += len - curlen; //채워야 하는 길이만큼 뒤에다가 ksa 반복해주면 됨

	curlen = len;
	pt = 1;
	for (int i = 0; i < ksa.length(); i++)
	{
		if (ksa[i] == p[pt])
		{
			pt = (pt + 1) % 3;
		}
		else
		{
			s++;
			curlen--; //현재 길이를 지운다.
		}
	}
	s += 1; // s앞에 k를 붙여야 되니까 len도 같이 더해준다.
	curlen += 1;
	s += len - curlen;

	curlen = len;
	pt = 2;
	for (int i = 0; i < ksa.length(); i++)
	{
		if (ksa[i] == p[pt])
		{
			pt = (pt + 1) % 3;
		}
		else
		{
			a++;
			curlen--; //현재 길이를 지운다.
		}
	}
	a += 2; // a앞에 k,s를 붙여야 하니까.
	curlen += 2;
	a += len - curlen;


	cout << min({ k,s,a });


	return 0;
}