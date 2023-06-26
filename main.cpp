#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int main(int argc, char* argv[]){
  //cout << "argc = " << argc << endl;
  //cout << "argv[1] = " << argv[1] << endl;
  //cout << "argv[2] = " << argv[2] << endl;

  if(argc <= 1)
  {
    cout << "please input Data." << endl;
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

  cerr << "read file form " << file_path << endl;

  stringstream buffer;

  buffer << file.rdbuf();

  string file_contents;

  file_contents = buffer.str();

  file.close();

  int adenine = 0, thymine = 0, guanine = 0, cytosine = 0;
  char genome;

  for(int i = 0; i < file_contents.size(); i++)
  {
    genome = file_contents[i];

    switch (genome) {
      case 'A':
        adenine++;
        break;
      case 'T':
        thymine++;
        break;
      case 'G':
        guanine++;
        break;
      case 'C':
        cytosine++;
        break;
      default:
        break;  
    }
  }

  cout << "A = " << adenine << endl;
  cout << "C = " << cytosine << endl;
  cout << "G = " << guanine << endl;
  cout << "T = " << thymine << endl;

  ofstream fileOut;
  string output_name;

  if(argc > 2){

    output_name = argv[2];
    output_name += ".txt";
  
  } else {

    output_name = "output.txt";

  }

  fileOut.open(output_name);

  fileOut << adenine << " " << cytosine << " " << guanine << " " << thymine << endl;

  fileOut.close();

  cerr << "write Result to " << output_name << endl;

  return 0;
}