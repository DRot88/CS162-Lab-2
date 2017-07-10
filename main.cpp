#include <iostream>
#include <fstream>
#include <string>
#include "letters.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
  string inFileName; // to store the name of the input file
  ifstream ifs; // create the input file stream
  int *letterArray;

  cout << "Please enter the name of the file you would like to search: ";
  cin >> inFileName;
  ifs.open(inFileName);

  if (!ifs) {
    cout << "Unable to open file: " << inFileName << endl;
    return 1;
  }

  letterArray = new int[26];
  count_letters(ifs, letterArray);

  ifs.close();

  delete [] letterArray;

  return 0;
}