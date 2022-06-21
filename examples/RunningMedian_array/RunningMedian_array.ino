//
//    FILE: RunningMedian.ino
//  AUTHOR: Rob Tillaart ( kudos to Sembazuru)
// PURPOSE: array of runningMedian objects
//    DATE: 2022-06-21
//     URL: https://github.com/RobTillaart/RunningMedian


#include <RunningMedian.h>

RunningMedian a(5);
RunningMedian b(10);
RunningMedian c(15);
RunningMedian d(20);

RunningMedian RM[4] = { a, b, c, d };

uint8_t pins[4] = { A0, A1, A2, A3 };

void setup()
{
  Serial.begin(115200);
  Serial.print("Running Median Version: ");
  Serial.println(RUNNING_MEDIAN_VERSION);

}


void loop()
{
  for (int i = 0; i < 4; i++)
  {
    RM[i].add(random(100));
  }
  for (int i = 0; i < 4; i++) 
  {
    Serial.print(RM[i].getCount());
    Serial.print("\t");
    Serial.print(RM[i].getMedian());
    Serial.print("\t");
  }
  Serial.println();
  delay(500);
}


// -- END OF FILE --
