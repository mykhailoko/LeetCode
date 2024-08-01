class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;

        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();
            radiant.pop();
            dire.pop();
            
            if (rIndex < dIndex) {
                radiant.push(rIndex + senate.size());
            } else {
                dire.push(dIndex + senate.size());
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
