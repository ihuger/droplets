max_int = 2**31-1
min_int = -max_int-1
class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        m = str(x)
        t = 1
        if x < 0:
            m = m[1:]
            t = -1
        v = t * int(m[::-1])
        if v>max_int or v<min_int:
            return 0
        return v

if __name__ == "__main__":
    print Solution().reverse(10000)
    print Solution().reverse(10)
    print Solution().reverse(12)
    print Solution().reverse(-112)
    print Solution().reverse(-1000000)
    print Solution().reverse(1223372036854775859)
    print Solution().reverse(-1223372036854775859)

