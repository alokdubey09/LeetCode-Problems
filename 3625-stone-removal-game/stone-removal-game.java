class Solution {
    public boolean canAliceWin(int n) {
        
        int pile =10;
        boolean aliceWin = false;
        while(n>=pile){
             n-=pile;
             pile--;
            aliceWin = !aliceWin;
        }
        return aliceWin;
    }
}