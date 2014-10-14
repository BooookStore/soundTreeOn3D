#include "ofMain.h"
#include "JugeCreateTiming.h"

class JugeTopHeight : public JugeCreateTiming
{
public:
    JugeTopHeight();
    JugeTopHeight(float height);

public:
    void setJugeHeight(float value);

public:
    virtual bool getJuge(float value1,float value2) const;

private:
    float m_jugeHeight;
};
