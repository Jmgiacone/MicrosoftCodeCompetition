#include <iostream>
#include <fstream>

using namespace std;
const float SECONDS_IN_MINUTE = 60,
              SECONDS_IN_HOUR = 60 * SECONDS_IN_MINUTE,
              MINUTE_HAND_AROUND_CLOCK = 12,
              SECOND_HAND_AROUND_CLOCK = 720, 
              SECONDS_ON_CLOCK = 43200;
void calcAngle(int hour, int minute, int second);
int main()
{
  ifstream in("SampleInput.txt");
  ofstream out("Output.txt");

  int numTimes = 0;

  in >> numTimes;

  /*for(int i  = 0; i < numTimes; i++)
  { 
        
  }*/

  calcAngle(10, 10, 10);
}

void calcAngle(int hour, int minute, int second)
{
  //int hour, minute, second;
  float hourAngle, minuteAngle, secondAngle;

  float hourToMin, hourToSec, minToSec;

  hour *= SECONDS_IN_HOUR;
  minute *= SECONDS_IN_MINUTE;
  
  hour = hour + minute + second;
  minute += second;

  hourAngle = 360 * (hour / SECONDS_ON_CLOCK);
  minuteAngle = 360 * ((minute * MINUTE_HAND_AROUND_CLOCK) / SECONDS_ON_CLOCK);
  secondAngle = 360 * ((second * SECOND_HAND_AROUND_CLOCK) / SECONDS_ON_CLOCK);
 
  cout << hourAngle << " " << minuteAngle << " " << secondAngle << endl; 
  /*if(hourAngle > 180)
  {
    hourAngle = 360 - hourAngle;
  }
  if(minuteAngle > 180)
  {
    minuteAngle = 360 - minuteAngle;
  }
  if(secondAngle > 180)
  {
    secondAngle = 360 - secondAngle
  }*/

  if(hourAngle > 180 && minuteAngle < 180)
  {}
  if(hourAngle < 180 && minuteAngle > 180)
  {}
  if(hourAngle < 180 && minuteAngle < 180)
  {}
  if(hourAngle > 180 && minuteAngle > 180)
  {}
  
  hourToMin = hourAngle + minuteAngle;
  hourToSec = hourAngle + secondAngle;
  minToSec = minuteAngle + secondAngle;

  std::cout <<  hourToMin << " " <<  hourToSec << " " << minToSec << endl;
}
