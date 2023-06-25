#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

int main(int argc, char* argv[]){
  //cout << "argc = " << argc << endl;
  //cout << "argv[1] = " << argv[1] << endl;

  if(argc <= 1)
  {
    cout << "please input txt." << endl;
    return 1;
  }

  char* file_path;
  file_path = argv[1];

  ifstream file;
  file.open(file_path);

  if(file.fail())
  {
    cout << "File failed to open." << endl;
    return 1;
  }

  stringstream buffer;

  buffer << file.rdbuf();

  string file_contents;

  file_contents = buffer.str();

  cout << file_contents;

  file.close();

  return 0;
}