
[![Arduino CI](https://github.com/RobTillaart/RunningMedian/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/RunningMedian/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/RunningMedian.svg?maxAge=3600)](https://github.com/RobTillaart/RunningMedian/releases)

# RunningMedian

Arduino library to determine the running median by means of a circular buffer.

## Description

Running Median looks like a running average with a small but important twist.
Running average averages the last N samples while the running median takes 
the last N samples, sort them and take the middle one, or the average of the middle two.

Important differences between running average and running median:
- Running median will return real data (e.g. a real sample from a sensor) 
if one uses an odd size of the buffer (preferred).
Running average may return a value that is never sampled.
- Running median will give zero weight to outliers, and 100% to the middle sample, 
whereas running average gives the same weight to all samples.
- Running median will give often constant values for some time.
- As one knows the values in the buffer one can predict to some extend how much 
the next samples will change the running median. 
- Running median is a bit harder as one needs to keep the values in order 
to remove the oldest and keep them sorted to be able to select the median.


#### Note MEDIAN_MAX_SIZE

The maxsize of the internal buffer is defined by **MEDIAN_MAX_SIZE** 
and is currently set to 19. This value is reasonable for most applications.
This define can be changed in the .h file or overruled compiletime.
Be aware that the library will consume more memory as it allocates 
**MEDIAN_MAX_SIZE** elements internally.


## Interface


### Constructor

- **RunningMedian(const uint8_t size)** Constructor
- **~RunningMedian()** 
- **uint8_t getSize()** returns size of internal array
- **uint8_t getCount()** returns current used elements, getCount() <= getSize()


### Base functions

- **clear()** resets internal buffer and var
- **add(const float value) ** adds a new value to internal buffer, optionally replacing the oldest element.
- **float getMedian()** returns the median == middle element
- **float getAverage()** returns average of the values in the internal buffer
- **float getAverage(uint8_t nMedian)** returns average of the middle nMedian values, removes noise from outliers
- **float getHighest()** idem
- **float getLowest()** idem
- **float getQuantile(const float q)** returns the Quantile


### Less used functions

- **float getElement(const uint8_t n)** returns the n'th element from the values in time order
- **float getSortedElement(const uint8_t n)** returns the n'th element from the values in size order (ascending)
- **float predict(const uint8_t n)** predict the max change of median after n additions, n should be smaller than **getSize()/2**


## Operation

See examples
