//
//    FILE: runningMedian_performance.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test performance
//     URL: https://github.com/RobTillaart/RunningMedian

#include <RunningMedian.h>

// 50 consecutive samples from Sharp distance sensor model GP2Y0A710K0F while stationary.
const int sourceData[] =
{
  //  test array
  //  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
  //  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  //  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  //  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  //  1, 2, 3, 4, 5, 6, 7, 8, 9, 10

  300, 299, 296, 343, 307, 304, 303, 305, 300, 340,
  308, 305, 300, 304, 311, 304, 300, 300, 304, 304,
  284, 319, 306, 304, 300, 302, 305, 310, 306, 304,
  308, 300, 299, 304, 300, 305, 307, 303, 326, 311,
  306, 304, 305, 300, 300, 307, 302, 305, 296, 300
};

const int sourceSize = (sizeof(sourceData) / sizeof(sourceData[0]));

// RunningMedian samples = RunningMedian(sourceSize);
RunningMedian samples = RunningMedian(sourceSize / 2);

void setup()
{
  Serial.begin(115200);
  while (!Serial);  //  Wait for serial port to connect. Needed for Leonardo + MKR1010.
  delay(1000);
  Serial.print(F("Running Median Version: "));
  Serial.println(RUNNING_MEDIAN_VERSION);

#ifdef RUNNING_MEDIAN_USE_MALLOC
  Serial.println(F("Dynamic version using malloc() enabled"));
#else
  Serial.print(F("Static version, will always allocate an array of "));
  Serial.print(MEDIAN_MAX_SIZE, DEC);
  Serial.println(F(" floats."));
#endif

  test1();

  Serial.println("\ndone..\n");
}

void loop()
{
}

void test1()
{
  uint32_t start = 0;
  uint32_t stop  = 0;
  uint32_t total = 0;

  Serial.print(F("Allocated size = "));
  Serial.println(samples.getSize());
  Serial.println();

  for (uint8_t i = 0; i < sourceSize; i++)
  {
    start = micros();
    samples.add(sourceData[i]);
    total += (micros() - start);
  }
  Serial.print(F("50 x add: "));
  Serial.println(total);
  Serial.print(F("     avg: "));
  Serial.println(total / 50.0);
  delay(100);

  // time to access the data
  start = micros();
  float result = samples.getMedian();
  stop = micros();
  Serial.print(F(" 1 x get: "));
  Serial.print(stop - start);
  Serial.println(F("       == sorting"));
  Serial.print(  "  median: ");
  Serial.println(result);
  delay(100);

  // time to access the data
  start = micros();
  result = samples.getMedian();
  stop = micros();
  Serial.print(F(" 1 x get: "));
  Serial.print(stop - start);
  Serial.println(F("       == no sorting"));
  Serial.print(  "  median: ");
  Serial.println(result);
  delay(100);

}

// -- END OF FILE --