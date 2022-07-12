#include <bits/stdc++.h>
using namespace std;
vector<int> use(10);

struct node
{
	char c;
	int v;
};

int check(node* nodearr, const int count, string s1, string s2, string s3)
{
	int V1 = 0, V2 = 0, V3 = 0, m = 1, j, i;

	for (i = s1.length() - 1; i >= 0; i--)
	{
		char ch = s1[i];
		for (j = 0; j < count; j++)
			if (nodearr[j].c == ch)
				break;

		V1 += m * nodearr[j].v;
		m *= 10;
	}
	m = 1;

	for (i = s2.length() - 1; i >= 0; i--)
	{
		char ch = s2[i];
		for (j = 0; j < count; j++)
			if (nodearr[j].c == ch)
				break;

		V2 += m * nodearr[j].v;
		m *= 10;
	}
	m = 1;

	for (i = s3.length() - 1; i >= 0; i--)
	{
		char ch = s3[i];
		for (j = 0; j < count; j++)
			if (nodearr[j].c == ch)
				break;

		V3 += m * nodearr[j].v;
		m *= 10;
	}

	if (V3 == (V1 + V2))
		return 1;
	    return 0;
}
bool modification(const int count, node* nodearr, int n, string s1, string s2, string s3)
{
	if (n == count - 1)
	{
		for (int i = 0; i < 10; i++)
		{
			if (use[i] == 0)
			{
				nodearr[n].v = i;
				if (check(nodearr, count, s1, s2, s3) == 1)
				{
					cout << "\nSolution found: ";
					for (int j = 0; j < count; j++)
						cout << " " << nodearr[j].c << " = "
							<< nodearr[j].v;
					return true;
				}
			}
		}
		return false;
	}

	for (int i = 0; i < 10; i++)
	{	
		if (use[i] == 0)
		{			
			nodearr[n].v = i;			
			use[i] = 1;
			
			if (modification(count, nodearr, n + 1, s1, s2, s3))
				return true;		
			use[i] = 0;
		}
	}
	return false;
}
bool Verdis(string s1, string s2, string s3)
{	
	int count = 0;
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = s3.length();

	vector<int> freq(26);

	for (int i = 0; i < l1; i++)
		++freq[s1[i] - 'A'];

	for (int i = 0; i < l2; i++)
		++freq[s2[i] - 'A'];

	for (int i = 0; i < l3; i++)
		++freq[s3[i] - 'A'];
	
	for (int i = 0; i < 26; i++)
		if (freq[i] > 0)
			count++;

	if (count > 10)
	{
		cout << "INVALID STRINGS";
		return 0;
	}	
	node nodearr[count];	
	for (int i = 0, j = 0; i < 26; i++)
	{
		if (freq[i] > 0)
		{
			nodearr[j].c = char(i + 'A');
			j++;
		}
	}
	return modification(count, nodearr, 0, s1, s2, s3);
}
int main()
{
	string s1 = "SEND";
	string s2 = "MORE";
	string s3 = "MONEY";

	if (Verdis(s1, s2, s3) == false)
		cout << "NO SOLUTION";
	return 0;
}
