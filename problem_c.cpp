#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream input_file;
char filename[15];

int main(void){
	vector<int> length_array, number_array;
	int reader, termination = 0, remainingspace, totaldistance;

	cout << "Enter input file path: ";                      /*input file path entry*/
	cin >> filename;
	input_file.open(filename);

	input_file >> totaldistance;
	while (termination == 0)
	{

		input_file >> reader;
		if (reader == 0)
		{
			termination = 1;
			break;
		}
		else
		{
			length_array.push_back(reader);
			input_file >> reader;
			number_array.push_back(reader);
		}
	}
	for (unsigned int i = 0 ; i<length_array.size() - 1 ; i++)
	{
		for (unsigned int j=0 ; j< (length_array.size() - i - 1) ; j++)
		{
			if ( length_array[j] < length_array[j+1] )
			{
				int intermediate = length_array[j];
				length_array [j] = length_array[j+1];
				length_array [j+1] = intermediate;
				intermediate = number_array[j];
				number_array [j] = number_array[j+1];
				number_array [j+1] = intermediate;
			}
		}
	}

	unsigned int numberofrods = 0;
	unsigned int minimum = 20000;
	int trial = 0;
	termination = 0;
	for (unsigned int j = 0 ; j<length_array.size() ; j++ )
	{
		int dec,firstdec=0;
		int number =1;
		while((number_array[j] - firstdec) > 0)
		{
			
			numberofrods  = 0;
			remainingspace = totaldistance;
			for (unsigned int i=j ; i<length_array.size() ; i++)
			{
				dec = i==j?firstdec:0;
				int rods = remainingspace/length_array[i];
				number = rods<number_array[i] ? (rods - dec) : (number_array[i] - dec);
				numberofrods+= number;
				remainingspace -= (length_array[i]*number);
				if (remainingspace == 0)
					break;
			}
			if (remainingspace == 0)
				minimum = minimum > (numberofrods-1) ? (numberofrods-1) : minimum;
			firstdec++;
		}
	}
	if (minimum < 20000)
		cout << minimum;
	else
		cout << "No Solution Available";
	input_file.close();
	system("pause");
	return 0;
	
}

		
