class Solution {
    fun arrangeCoins(n: Int): Int {
        var s:Long = 0.toLong()
        var e:Long = Integer.MAX_VALUE.toLong()
        while (s <= e) {
            val m = (s + e) / 2
            m.toLong()
            if(m*(m+1)/2 > n) e = m - 1
            else s = m + 1
        }
        return e.toInt()
    }
}