#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	int n, m;

	cin >> str >> m;
	n = str.length();

	list<char> L;
		
	for (auto c : str)
		L.push_back(c);

	list<char>::iterator itr = L.end();

	for (int i = 0; i < m; i++)
	{
		char instr;
		cin >> instr;
		switch (instr)
		{
		case 'L':
			if (itr != L.begin())
				itr--;
			break;
		case 'D':
			if (itr != L.end())
				itr++;
			break;
		case 'B':
			if (itr != L.begin())
				itr = L.erase(--itr);
			break;
		case 'P':
			char ch;
			cin >> ch;
			L.insert(itr, ch);
			break;
		}
	}
	
	for (itr = L.begin(); itr != L.end(); itr++)
	{
		cout << *itr;
	}



}
