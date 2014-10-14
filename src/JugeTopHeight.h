#include "ofMain.h"
#include "JugeCreateTiming.h"

class JugeTopHeight : public JugeCreateTiming
{
public:
    JugeTopHeight();
    JugeTopHeight(float height);

public:
    void updateHeight();

public:
    void setDecreaseJugeHeight(float amount);

public:
    virtual bool getJuge(ofPoint top,ofPoint down) const;

private:
    float m_jugeHeight;
    float m_decrease;
};
