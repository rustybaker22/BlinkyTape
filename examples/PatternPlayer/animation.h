#ifndef ANIMATION_H
#define ANIMATOR_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define ENCODING_NONE  0
#define ENCODING_RLE   1
#define ENCODING_16RLE 2

class animation {
 private:
  uint16_t m_frameCount;
  prog_uint8_t* m_frameData;
  uint8_t m_encoding;
  uint8_t m_ledCount;
  
  uint16_t m_frameIndex;
  prog_uint8_t* currentFrameData;

  void drawNoEncoding(Adafruit_NeoPixel& strip);  
  void drawRLE(Adafruit_NeoPixel& strip);
  void draw16bitRLE(Adafruit_NeoPixel& strip);
  
 public:
  // Declare an animation, where the animation type and frame count are encoded in the frame data
  // (for easier munging of the HEX file)
  animation(const prog_uint8_t* animationData);
  
  // Declare an animation in a more reasonable manner.
  animation(uint16_t frameCount, const prog_uint8_t* frameData, const uint8_t encoding = ENCODING_NONE);
 
  // Reset the animation
  void reset();
  
  // Draw the next frame of the animation
  void draw(Adafruit_NeoPixel& strip);
};

#endif
