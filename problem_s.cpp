#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#define PI 3.14

using namespace std;

int main()
{
	double point, previouspoint, angle, area = 0, initial;
	int counter;
	char input[10];
	cin >> previouspoint;
	initial = previouspoint;
	counter = 0;
	while ((int) previouspoint != '$')
	{
		cin >> input;
		
		if (input[0] == '$')
			break;
		else
			point = atof(input);
		angle = point - previouspoint;
		area += 0.5*( abs( sin(angle*PI)));
		previouspoint = point;
		counter += 1;
	}
	angle = point - initial;
	if(counter > 1)
	{
		if(point <=1)
		{
			area -= 0.5*( abs( sin(angle*PI)));
		}
		else
		{
			area += 0.5*( abs( sin(angle*PI)));
		}
	
	}
	
	cout << fixed;
	cout << setprecision(2) << area;
	return 0;
}
