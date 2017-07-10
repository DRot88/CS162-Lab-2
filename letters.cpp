#include "letters.hpp"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

const int ASCII_A = 65;
const int ASCII_Z = 90;

void count_letters(ifstream & inputStream, int* arr){
  char singleChar; // to read in individual characters
  char upper;
  string outFileName; // to store the name of the output file
  ofstream ofs; // create the output file stream


  // set initial count to 0 for all values at every index
  for (int i = 0; i < 26; i++) {
    arr[i] = 0;
  }

  singleChar = inputStream.get(); // read in next character
  while (singleChar != EOF) { // while not end of file
    upper = (char)toupper(singleChar); // store uppercase value
    for (int i = ASCII_A; i <= ASCII_Z; i++) { // loop through alphabet, if match, increase frequency
      if (upper == i) {
        arr[i-65] += 1;
      }
    }
    singleChar = inputStream.get(); // read in next character before next loop iteration
  }

  cout << "Please enter the name of the file you would like to output data to: ";
  cin >> outFileName;
  ofs.open(outFileName);
  output_letters(ofs, arr);
  ofs.close();
}

void output_letters(ofstream & outputStream, int* outArr){
  for (int i = 0; i < 26; i++) {
    outputStream << (char)('A' + i) << ": " << outArr[i] << endl;
  }
}
