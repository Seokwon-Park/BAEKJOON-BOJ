#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 3; i++)
	{
		int sh, sm, ss, eh, em, es;
		cin >> sh >> sm >> ss >> eh >> em >> es;
		int h, m, s;
		int carry = 0;
		if (es - ss < 0)
		{
			s = es - ss + 60;
			carry = 1;
		}
		else
			s = es - ss;
		if (em - sm - carry < 0)
		{
			m = em - sm - carry + 60;
			carry = 1;
		}
		else
		{
			m = em - sm- carry;
			carry = 0;
		}

		h = eh - sh - carry;

		cout << h << ' ' << m  << ' ' << s << '\n';;
	}
	return 0;
}