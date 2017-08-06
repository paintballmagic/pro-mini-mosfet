

#ifndef DEBUG_H
#define DEBUG_H

// leave these defines alone
#define DEBUG_MODE true
#define DEBUG_TRIGGER_LOGIC true

// comment out items below to turn them on
//#undef DEBUG_MODE
//#undef DEBUG_TRIGGER_LOGIC

#ifdef DEBUG_MODE
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

#endif

