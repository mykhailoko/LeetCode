class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for (int i = 0; i<asteroids.size(); ){
            if ((i + 1 < asteroids.size()) and (asteroids[i] > 0) and (asteroids[i+1] < 0)){
                if (asteroids[i] == -asteroids[i+1]){
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    i = 0;
                } else if (asteroids[i] > -asteroids[i+1]){
                    asteroids.erase(asteroids.begin() + i + 1);
                    i = 0;
                } else {
                    asteroids.erase(asteroids.begin() + i);
                    i = 0;
                }
            } else {
                i++;
            }
        }
        return asteroids;
    }
};
