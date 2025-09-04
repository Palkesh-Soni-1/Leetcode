class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distance1 = abs(z - x);
        int distance2 = abs(z - y);
        if (distance1 > distance2) return 2;
        else if (distance1 < distance2) return 1;
        else return 0;
    }
};
