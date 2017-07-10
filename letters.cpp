#include "letters.hpp"
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

const int ASCII_A = 65;
const int ASCII_Z = 90;

// What you can do is put your current count_letter function into another function, 
// with a parameter to pass in a string (paragraph), then inside your count_letter function split 
// the texts by paragraphs, and call the new function that counts letters in each paragraph.

void count_letters(ifstream & inputStream, int* arr) {
  //set all elements in array to count of 0;
  char ch;
  char upper;
  string paragraph;
  string outFileName;
  ofstream ofs;

  for (int i = 0; i < 26; i++) {
    arr[i] = 0;
  }

  while(getline(inputStream, paragraph)) {
    stringstream ss;
    ss << paragraph;

    while(ss >> ch) {
      upper = (char)toupper(ch); // store uppercase value
      for (int i = ASCII_A; i <= ASCII_Z; i++) { // loop through alphabet, if match, increase frequency
        if (upper == i) {
          arr[i-ASCII_A] += 1;
        }
      }
    }
  cout << "Please enter the name of the file you would like to output data to: ";
  cin >> outFileName;
  ofs.open(outFileName);
  output_letters(ofs, arr);
  ofs.close();

  for (int i = 0; i < 26; i++) {
    arr[i] = 0;
  }

  }
}

void output_letters(ofstream & outputStream, int* outArr){
  for (int i = 0; i < 26; i++) {
    outputStream << (char)('A' + i) << ": " << outArr[i] << endl;
  }
}


/****************************************************************************
            WORKING CODE FOR ENTIRE FILE LETTER FREQUENCY
*****************************************************************************
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
        arr[i-ASCII_A] += 1;
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
******************************************************************************
******************************************************************************/
