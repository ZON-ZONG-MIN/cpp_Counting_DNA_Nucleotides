#include <fstream>
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main(int argc, char* argv[]){
  ifstream fileIn;
  int score1, score2, score3, score4, score5;
  double average = 0;
  char* argv_input;

  cout << "argc = " << argc << endl;
  cout << "argv[1] = " << argv[1] << endl;
/*
  if(argc > 1){

    fileIn.open(argv_input);

    fileIn >> score1;

    fileIn.close();
  }
*/
  //fileIn.open("./input/test.txt");
  
  //fileIn >> score1 >> score2 >> score3 >> score4 >> score5;
  
  //fileIn.close();

  /*cout << score1 << ','
      << score2 << ','
      << score3 << ','
      << score4 << ','
      << score5 << endl;*/

  if(argc > 1){

    argv_input = argv[1];
    ofstream fileOut;

    fileOut.open("./input/output.txt");
    
    cout << argv_input << endl;
    fileOut << argv_input << endl;
    
    fileOut.close();
  }

  return 0;
}