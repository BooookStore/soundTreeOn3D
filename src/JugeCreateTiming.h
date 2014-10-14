#include "ofMain.h"

class JugeCreateTiming {
public:
    virtual ~JugeCreateTiming(){};
public:
    virtual bool getJuge(float value1,float value2) const = 0;
};
