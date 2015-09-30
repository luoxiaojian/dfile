#include "dfile.h"
#include <iostream>
using namespace std;
int main()
{
	string infile="file1.txt";
	dfile file(infile, 8);
	char* content=(char *)file.getData();
	cout<<content[0]<<endl;
	return 0;
}
