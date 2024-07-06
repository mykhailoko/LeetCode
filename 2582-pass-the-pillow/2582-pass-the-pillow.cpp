class Solution {
public:
    int passThePillow(int n, int time) {
        int pillow = 1;
        bool direction = true;
        while (time != 0){
            if(pillow == 1){
                direction = true;
            }
            if(pillow == n){
                direction = false;
            }
            if (direction == true){
                pillow += 1;
            }
            if (direction == false){
                pillow -= 1;
            }
            time -= 1;
        }
        return pillow;
    }
};
