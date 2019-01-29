#include <iostream>
#include <fstream>
//#include <cstdio> prinft would print it as wanted.
//#include <string> //Could be used to verify argv is correct filetype.

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
void expandArray(int *&arr, int &arraySize);
//bool has_suffix(const std::string &str, const std::string &suffix);
//bool validFile(int argc, char** argv, string &readFromFile);
int main(int argc, const char * argv[])
{
    std::ifstream myReadFile;
    /*if(!validFile(argc, argv, string &readFromFile){return -1;} Validate fileformat and that the program got any argv at all if not exit with -1
else{*/
    myReadFile.open(argv[1]);
    int arraySize = 3;
    int *numbers = new int[arraySize];
    int nrOfNumbers = 0;
    int inputFromFile = 0; //Better description of variable then a
    int sum = 0;
    while (myReadFile >> inputFromFile)
    {
        if(nrOfNumbers == arraySize){
          expandArray(numbers, arraySize);
        }
        numbers[nrOfNumbers] = inputFromFile;
        nrOfNumbers++;
        sum += inputFromFile;
    }
    myReadFile.close();
    for(int i = 0; i < nrOfNumbers; i++)
    {
      if(numbers[i] < (sum/nrOfNumbers)){
        float printValue = numbers[i];
        printf("%.3f", printValue);
      }
    }
    delete[] numbers;
    return 0;
}


void expandArray(int *&arr, int &arraySize){ //For performance it can be bad to expand with only one each time since one might need to rerun it often but makes sure to not waste unused memory.
  int *temp = new int[arraySize+1];
  for(int i = 0; i < arraySize; i++)
  {
    temp[i] = arr[i];
  }
  delete [] arr;
  arr = temp;
  arraySize++;
}
/*bool validFile(int argc, char** argv, string &readFromFile) //Make sure it's a .txt file and not error because of incorect input file type.
{
        if (argc > 1) {
                readFromFile = argv[1];
        }
        if (!has_suffix(readFromFile, ".txt")) {
                return false;
        }
        else{
              	return true;
        }
}*/
