#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	string maxa = to_string(a);
	string maxb = to_string(b);

	string mina = to_string(a);
	string minb = to_string(b);

	for(int i =0; i< maxa.length(); i++)
	{ 
		if (maxa[i] == '5')
		{
			maxa[i] = '6';
		}

		if (mina[i] == '6')
		{
			mina[i] = '5';
		}
	}
	for (int i = 0; i < maxb.length(); i++)
	{
		if (maxb[i] == '5')
		{
			maxb[i] = '6';
		}

		if (minb[i] == '6')
		{
			minb[i] = '5';
		}
	}

	cout << stoi(mina) + stoi(minb) << ' ' << stoi(maxa) + stoi(maxb);

	return 0;
}