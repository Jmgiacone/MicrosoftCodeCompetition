#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int RIGHT = 1;
const int LEFT = 3;
const int COMPASS = 4;


int main()
{

  enum direction {north, east, south, west};
  direction face;
  int faceStorage;
  int steps[4] = {0,0,0,0};
  int stepOrder;
  int finalNorth = 0, finalEast = 0;
  string order;
  face = north;
  ifstream fin;
  ofstream fout;
  fin.open("SampleInput.txt");
  fout.open("Output.txt");
  while(!fin.eof())
  {
    fin >> order;
    if (order == "Move")
    {
      fin >> stepOrder;
      steps[face] += stepOrder;
    }
    else if (order == "Turn")
    {
      fin >> order;
      if (order == "right")
        faceStorage = ((face + RIGHT) % COMPASS);
      else if (order == "left")
        faceStorage = ((face + LEFT) % COMPASS);
      face = static_cast<direction>(faceStorage);
    }
  }
  finalNorth = steps[north] - steps[south];
  finalEast = steps[east] - steps[west];
  cout << finalNorth << " , " << finalEast << endl;
  fout << finalNorth << " , " << finalEast << endl;
  fout.close();
  fin.close();
  return 0;

}