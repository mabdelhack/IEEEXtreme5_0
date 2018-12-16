#include <iostream>
#define size 100000

using namespace std;

int main()
{
	int cases,students,R, G, end=0, start=0,index=0,added_marks=0;
	int marks[size];
	char action;
	int max[1000] = {0};
	cin >> cases;

	for(int i=0; i<cases; i++)
	{
		cin >> students >> R >> G;
		
		for(int j=0; j<students; j++)
			cin>> marks[j];
		for(int j=0; j<R; j++)
		{
			cin>> action >> index>> added_marks;
			marks[index-1] += added_marks;
			if (marks[index-1] > 100)
				marks[index-1] = 100;
		}
		for(int j=0;j<G;j++)
		{
			cin>> action>> start >> end;
			int sum = 0;
			for (int k=start-1; k<=end-1; k++)
			{
				sum += marks[k];
			}
			max[i] = sum>max[i] ? sum : max[i];
		}
	}
	for(int i=0; i<cases; i++)
	{
		cout << max[i];
		if (i!=(cases-1))
			cout << endl;
	}
	return 0;
}