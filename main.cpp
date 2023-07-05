#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <unistd.h>
#include <getopt.h>

using namespace std;

int main(int argc, char* argv[]){

  const char *optstring = "vi:o:h";
  int c;
  static const struct option opts[] = {
      {"version", 0, NULL, 'v'},
      {"input", 1, NULL, 'i'},
      {"help", 0, NULL, 'h'},
      {"output", 1, NULL, 'o'}
  };

  char* file_path = NULL;
  char* output_path = NULL;
  string command(argv[1]);
  argc--;
  argv++;

  while((c = getopt_long(argc, argv, optstring, opts, NULL)) != -1) {
      switch(c) {
          case 'i':
              printf("Input: %s\n", optarg);
              file_path = optarg;
              break;
          case 'v':
              printf("version: 0.0.1\n");
              break;
          case 'h':
              printf("help:\n");
              printf("  -h: help\n");
              printf("  -v: version\n");
              printf("  -i: input file path\n");
              printf("  -o: ioutput file path\n");
              break;
          case 'o':
              printf("output: %s\n", optarg);
              output_path = optarg;
              break;
          case '?':
              printf("unknown option\n");
              return 1;
              break;
          case 0 :
              printf("the return val is 0\n");
              break;
          default:
              printf("------\n");

      }
    }

  if(argc <= 1)
  {
    cout << "please input Data." << endl;
    return 1;
  }

  /*read file from input path*/

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

  if(command=="dna"){

    cout << argc << argv[1] << endl;
    /* compute DNA string ... */
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

    /*write output*/
    ofstream fileOut;

    if(output_path == NULL){
      char output[] = "output.txt";
      output_path = output;
    }

    fileOut.open(output_path);

    fileOut << adenine << " " << cytosine << " " << guanine << " " << thymine << endl;

    fileOut.close();

    cerr << "write Result to " << output_path << endl;

  } else if(command=="rna") {

    /* Transcribing DNA into RNA ... */
    for(int i = 0; i < file_contents.size(); i++){
      if(file_contents[i] == 'T')
        file_contents[i] = 'U';
    }
    cout << file_contents << endl;

    /*write output*/
    ofstream fileOut;

    if(output_path == NULL){
      char output[] = "output.txt";
      output_path = output;
    }

    fileOut.open(output_path);

    fileOut << file_contents;

    fileOut.close();

    cerr << "write Result to " << output_path << endl;
  }
  
  return 0;
}