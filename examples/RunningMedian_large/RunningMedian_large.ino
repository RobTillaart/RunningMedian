//
//    FILE: RunningMedian2.ino
//  AUTHOR: Rob Tillaart ( kudos to Sembazuru)
// VERSION: 0.1.2
// PURPOSE: demo most functions
//    DATE: 2013-10-17
//     URL: https://github.com/RobTillaart/RunningMedian
//

#include "RunningMedian.h"

RunningMedian samples = RunningMedian(101);

long count = 0;

void setup()
{
  Serial.begin(115200);
  Serial.print(F("Running Median Version: "));
  Serial.println(RUNNING_MEDIAN_VERSION);

  Serial.println(samples.getSize());
}

void loop()
{
}
