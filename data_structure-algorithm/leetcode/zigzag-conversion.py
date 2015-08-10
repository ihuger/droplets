
class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        l = [""]*numRows
        x = 2*numRows-2
        if x == 0 :
            return s

        for ct in range(len(s)):
            m = ct % x
            if m < numRows:
                l[m] += s[ct]
            else:
                l[x-m] += s[ct]
        return "".join(l)

if __name__ == "__main__":
    #s = "PAYPALISHIRING"
    s = "A"
    numRows = 1
    print Solution().convert(s,numRows)

