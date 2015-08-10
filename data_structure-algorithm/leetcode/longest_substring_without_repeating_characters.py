class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        m = 0
        d = {}
        start = 0

        for i in range(len(s)):
            if s[i] not in d or d[s[i]] < start:
                m = max(m,i-start + 1)
            else:
                start = d[s[i]] + 1
            d[s[i]] = i

        return m


    # @param {string} s
    # @return {integer}
    def _lengthOfLongestSubstring(self, s):
        m = 0
        start = 0
        for i in range(len(s)):
            j = start
            while j < i:
                if s[i] == s[j]:
                    start = j + 1
                    break
                j+=1
            if j >= i:
                m = max(m,j-start + 1)
        return m

if __name__ == "__main__":
    print Solution().lengthOfLongestSubstring('abcabcbb')
    print Solution().lengthOfLongestSubstring('abcaddcabef')
