#include <fstream>
#include <iostream>
using namespace std;

int main(){
  ifstream fileIn;
  int score1, score2, score3, score4, score5;
  double average = 0;

  fileIn.open("./input/test.txt");
  
  fileIn >> score1 >> score2 >> score3 >> score4 >> score5;
  
  fileIn.close();

  cout << score1 << ','
      << score2 << ','
      << score3 << ','
      << score4 << ','
      << score5 << endl;

  return 0;
}