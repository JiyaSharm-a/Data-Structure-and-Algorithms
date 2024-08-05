class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hrAngle = (hour%12 + (float)minutes/60) * 30;
        float minAngle = minutes*6;

        float angle = abs(hrAngle - minAngle);

        if(angle > 180)
        {
            angle = 360 - angle;
        }
        return angle;
    }
};