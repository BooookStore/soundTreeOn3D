#include "ofMain.h"

class JugeCreateTiming {
public:
    virtual ~JugeCreateTiming(){};
public:
    virtual bool getJuge(ofPoint top,ofPoint down) const = 0;
};
