#include "Sort.h"
#include <fstream>
#include <iostream>
#include <chrono>
using namespace std;
using ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

int main(int argc, const char *argv[])
{
  string f = argv[1]; // command line argument for the input file
  ifstream doubleFile;
  doubleFile.open(f);

  int lineCount = 0;
  string line;
  while (getline(doubleFile, line))
    ++lineCount;

  doubleFile.clear(); // this line and next line are for resetting open file
  doubleFile.seekg(0, doubleFile.beg);

  double  myArray[lineCount];

  for (int i = 0; i < lineCount; ++i)
    doubleFile >> myArray[i];

  double myArray2[lineCount];
  double myArray3[lineCount];

  for (int i = 0; i < lineCount; ++i)
  {
    myArray2[i] = myArray[i];
    myArray3[i] = myArray[i];
  }

  auto startInsert = get_time::now();
  Sort::insertSort(myArray, lineCount);
  auto endInsert = get_time::now();
  auto diffInsert = endInsert - startInsert;
  cout << "elapsedTime for insertSort : " << chrono::duration_cast<ns>(diffInsert).count() << " ns " << endl;

  auto startQuick = get_time::now();
  Sort::quickSort(myArray2, 0, lineCount - 1);
  auto endQuick = get_time::now();
  auto diffQuick = endQuick - startQuick;
  cout << "elapsedTime for quickSort : " << chrono::duration_cast<ns>(diffQuick).count() << " ns " << endl;

  auto startBubble = get_time::now();
  Sort::bubbleSort(myArray3, lineCount);
  auto endBubble = get_time::now();
  auto diffBubble = endBubble - startBubble;
  cout << "elapsedTime for bubbleSort : " << chrono::duration_cast<ns>(diffBubble).count() << " ns " << endl;

  cout << "insertSort: " << endl;
  for (int i = 0; i < lineCount; ++i)
    cout << myArray[i] << endl;

  cout << "quickSort: " << endl;
  for (int i = 0; i < lineCount; ++i)
    cout << myArray2[i] << endl;

  cout << "bubbleSort: " << endl;
  for (int i = 0; i < lineCount; ++i)
    cout << myArray3[i] << endl;

  return 0;
}
