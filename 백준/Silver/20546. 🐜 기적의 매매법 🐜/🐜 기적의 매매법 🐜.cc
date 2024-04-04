#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(14);
	for (int& i : v)
		cin >> i;

	int astock = 0;
	int amoney = n;
	for (int i = 0; i < 14; i++)
	{
		astock += amoney / v[i];
		amoney %= v[i];
	}
	amoney += astock * *v.rbegin();
	
	int inc = 0;
	int dec = 0;
	int bstock = 0;
	int bmoney = n;
	for (int i = 1; i < 14; i++)
	{
		if (v[i - 1] < v[i])
		{
			dec = 0;
			inc++;
		}
		if (v[i - 1] > v[i])
		{
			inc = 0;
			dec++;
		}
		if (inc >= 3)
		{
			bmoney += bstock * v[i];
			bstock = 0;
		}
		if (dec >= 3)
		{
			bstock += bmoney / v[i];
			bmoney %= v[i];
		}
	}
	bmoney += bstock * *v.rbegin();

	if (amoney == bmoney)
		cout << "SAMESAME";
	else if (amoney > bmoney)
		cout << "BNP";
	else
		cout << "TIMING";


	return 0;
}