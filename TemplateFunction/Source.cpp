//Jay Rosen
//This program reads a txt file into two vectors of different data-types and sums the contents using a template function.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Template class declaration
template <class T>
T accum(vector <T> v)	//accum is a template function that will return the sum of integer vector or concatenate a string vector
{
	T sum = T();
	for (int i = 0; i < v.size(); i++)	//read each element of the vector
		sum += v[i];		//accumulation of the values in the vector
	return sum;				//returns ths sum of given data-type
}

class VectorFile
{
private:
	const int SIZE = 11;		//number of lines in tempData.txt file
	const int NUM_SIZE = 5;		//first 5 lines of tempData.txt
	const int STRING_SIZE = 6;	//second half of tempData.txt is 6 lines
	int count;
	int num;					//num are the int elements of vector
	string word;				//word are the string elemtns of vector
	vector<int> number;			//vector container for num
	vector <string> sentence;	//vector container for words
	void tempData();			//function to read tempData.txt
	void displayVector();		//function to display contents of integer and string vectors

public:
	void start();				//function to access VectorFile members from Main program
	ifstream txt;				//hold tempData.txt

};
/**************************************************************
*              VectorFile::start                               *
* This function displays introduction of program,              *
* pauses for user input, then calls tempData function.         *
**************************************************************/
void VectorFile::start()
{
	cout << "\n\n\t+------------------------------------------------------------+";
	cout << "\n\t| This program sums the contents of a text file.             |";
	cout << "\n\t| Make sure 'tempData.txt' is  located in current directory. |";
	cout << "\n\t|                                                            |";
	cout << "\n\t| Press ENTER to continue . . .                              |";
	cout << "\n\t+------------------------------------------------------------+\n\t";

	cin.get();

	tempData();

}

/**************************************************************
*              VectorFile::tempData                            *
* This function reads the data of tempData.txt                 *
* and initalizes two vectors of integer and string data-types. *
* This function also calls the displayVector member.           *
**************************************************************/
void VectorFile::tempData()
{
	//attempt to open txt file
	txt.open("tempData.txt");
	if (!txt)
		cout << "Error opening data file\n";
	//initalize the text file into the vectors
	else
	{
		count = 0;

		cout << "\n\t Reading file  ";

		//read first half of file into integer vector
		while (count < NUM_SIZE && txt >> num) 						//NUM_SIZE count up to 5
		{
			number.push_back(num);
			count++;
			//Display the progress of reading file into vector, I used a counter of 99 million to slow down the reading of numbers.
			for (int i = 0; i <= 99999999; i++);
			cout << count << "\b"; 					// escape character \b is to backspace previous count and write over with next count
		}

		//read second half of file into string vector
		while (count < SIZE && txt >> word) 			//This loop continues count where first loop left off, but counts up to 6 instead of 5
		{
			sentence.push_back(word);
			count++;
			for (int i = 0; i <= 99999999; i++);
			if (count > 10)								//create an extra backspace if count is more than 10 
			{
				cout << "\b";
			}
			cout << count << "\b";
		}

		txt.close();									//close txt file
	}

	displayVector();									//call function to display the vectors

}

/***********************************************************************
*              VectorFile::displayVector                                *
* This function displays the contents of the Class's vectors            *
* and uses a Template function to display the sum of vector's contents. *
************************************************************************/
void VectorFile::displayVector()
{
	//Display size of the integer vector
	cout << "\n\n\t+------------------------------------------------------------+";
	cout << "\n\t| Numbers found : " << number.size() << "                                          |";
	cout << "\n\t| ";

	//Display elements of integer vector
	for (count = 0; count < NUM_SIZE; count++)
	{
		cout << number[count] << " + ";
	}

	//Display integer sum by passing vector to template function accum
	cout << "\b\b\b = " << accum(number) << "                          |";
	cout << "\n\t+------------------------------------------------------------+\n\t";

	//Display size of the string vector
	cout << "\n\n\t+------------------------------------------------------------+";
	cout << "\n\t| Words found : " << sentence.size() << "                                            |";
	cout << "\n\t| ";

	//Display elements of string vector
	for (count = 0; count < STRING_SIZE; count++)
	{
		cout << sentence[count] << " + ";
	}

	//Display concatenated string by passing vector to accum function
	cout << " \b\b\b =          |";
	cout << "\n\t| " << accum(sentence) << "                            |";
	cout << "\n\t+------------------------------------------------------------+\n\t";

}

/**************************************************************
*                                                               *
* 							Main		   			            *
*                                                               *
*                                                               *
**************************************************************/

//small Main driver program that creates a program object, which starts the VectorFile class's functions
int main()
{
	VectorFile program;
	program.start();

	cout << "\n\n\t\a";

	system("pause");
	return 0;

}
