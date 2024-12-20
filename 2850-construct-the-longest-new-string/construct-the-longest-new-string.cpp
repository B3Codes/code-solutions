class Solution {
public:
    int longestString(int x, int y, int z) {
        string res = "";
        while(z){
            res = res + "AB";
            z--;
        }

        bool xTurn = true;
        (x > y) ? xTurn = true : xTurn = false;
        while(x && y){
            if(xTurn){
                res = res + "AA";
                x--;
            } else {
                res = res + "BB";
                y--;
            }
            xTurn = !xTurn;
        }

        if(x){
            res = res + "AA";
        }

        if(y){
            res = res + "BB";
        }

        return res.size();

    }
};