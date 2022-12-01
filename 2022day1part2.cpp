// Written by Conner Kincaid
// Used primarily in the Advent of Code 2021

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("input.txt");

    int elfnum[250] = {0};
    int CC = 0;
    int max = 0;
    int fatelf = 0;
    // process the data set lines
    while(getline(inFile, line))
    {
        //cerr << line << endl;
        if(isdigit(line[0]))
        {
            CC+=stoi(line);
        }
        else
        {
            elfnum[fatelf] = CC;
            CC=0;
            fatelf++;
        }
    }
   
    int n = sizeof(elfnum) / sizeof(elfnum[0]);
    sort(elfnum, elfnum + n);
 
    for (int i = 0; i < n; ++i)
        cout << elfnum[i] << " ";
   
   
   
    cout << endl << "Solution: "  << elfnum[247]+elfnum[248]+elfnum[249] << endl;
    inFile.close();
    return 0;
}
