#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	list<char> ll;

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		ll.clear();
		string l;
		cin >> l;
		list<char>::iterator itr = ll.begin();
		for (auto ch : l)
		{
			switch (ch)
			{
			case '<':
				if (itr != ll.begin())itr--;
				break;
			case '>':
				if (itr != ll.end())itr++;
				break;
			case '-':
				if (itr != ll.begin())
					itr = ll.erase(--itr);
				break;
			default:
				ll.insert(itr, ch);
			}
		}
		for (auto i = ll.begin(); i != ll.end(); i++)
			cout << *i;
		cout << '\n';
	}

	return 0;
}


