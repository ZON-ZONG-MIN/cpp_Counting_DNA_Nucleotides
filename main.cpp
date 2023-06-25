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

  int adenine = 0, thymine = 0, guanine = 0, cytosine = 0;
  char gene;

  for(int i = 0; i < file_contents.size(); i++)
  {
    gene = file_contents[i];
    if(gene == 'A')
      adenine++;
    if(gene == 'T')
      thymine++;
    if(gene == 'G')
      guanine++;
    if(gene == 'C')
      cytosine++;
  }

  cout << "A = " << adenine << endl;
  cout << "T = " << thymine << endl;
  cout << "G = " << guanine << endl;
  cout << "C = " << cytosine << endl;

  file.close();

  return 0;
}