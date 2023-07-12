//
//    FILE: RunningMedian_getMedianAverage.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test sketch
//     URL: https://github.com/RobTillaart/RunningMedian


#include <RunningMedian.h>

RunningMedian samples = RunningMedian(11);


void setup()
{
  Serial.begin(115200);
  Serial.print("Running Median Version: ");
  Serial.println(RUNNING_MEDIAN_VERSION);

  test1();

  samples.clear();
  samples.add(1);
  samples.add(2);

  delay(1000);
  uint32_t start = micros();
  float f = samples.getMedianAverage(1);
  uint32_t stop = micros();
  Serial.println(stop - start);
  Serial.println(f);
}


void loop()
{
}


void test1()
{
  for (int x = 0; x < 9; x++)
  {
    for (int y = 0; y <= x; y++)
    {
      Serial.print(x);
      Serial.print('\t');
      Serial.print(y);
      Serial.print('\t');
      Serial.println(samples.getMedianAverage(y));
    }
    Serial.println();
    samples.add(x);
  }
}


// -- END OF FILE --
