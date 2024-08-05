class Solution {
public:
    int check(int a,int b)
    {
        int c = 0, f = 0, l = 1;

        while(a > 0 || b > 0)
        {
            if(f == 0)
            {
                if(a >= l)
                {
                    a = a - l;
                }
                else
                break;
            }
            else
            {
                if(b >= l)
                {
                    b = b - l;
                }
                else
                break;
            }

            c++;
            l++;
            f = f ^ 1;
        }

        return c;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int k1 = check(red,blue);
        int k2 = check(blue,red);

        return max(k1,k2);
    }
};