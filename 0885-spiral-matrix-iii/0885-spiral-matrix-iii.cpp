class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> result;

        int r=rStart;
        int c=cStart;
        int radius=1;
        bool flag=true;

        while(flag){

            flag=false;

            //Go right 'radius' times
            for(int i=0; i<radius; i++){
                if(r>=0 && c>=0 && r<rows && c<cols){
                    result.push_back({r,c});
                    flag=true;
                }
                c++;
            }
            
            //Go down 'radius' times
            for(int i=0; i<radius; i++){
                if(r>=0 && c>=0 && r<rows && c<cols){
                    result.push_back({r,c});
                    flag=true;
                }
                r++;
            }

            //Go left 'radius'+1 times
            for(int i=0; i<radius+1; i++){
                if(r>=0 && c>=0 && r<rows && c<cols){
                    result.push_back({r,c});
                    flag=true;
                }
                c--;
            }

            //Go up 'radius'+1 times
            for(int i=0; i<radius+1; i++){
                if(r>=0 && c>=0 && r<rows && c<cols){
                    result.push_back({r,c});
                    flag=true;
                }
                r--;
            }

            radius=radius+2;
        }
        
        return result;
    }
};