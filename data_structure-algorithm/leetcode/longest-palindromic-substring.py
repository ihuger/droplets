#!/usr/bin/env python

class Solution:
    # @param {string} s
    # @return {string}
    def _longestPalindrome(self, s):
        l = [0]*len(s)
        x = -1
        m = 0
        for i in range(len(s)):
            for j in range(len(s))[::-1]:
                if s[len(s)-1-i] == s[j]:
                    if j >= 1:
                        l[j] = l[j-1] + 1
                    else:
                        l[j] = 1
                    if m < l[j]:
                        m = l[j]
                        x = j
                else:
                    l[j] = 0
            print ' '.join([ str(t) for t in l])
        print x,m, s[(x-m+1):(x+1)]
        #print s[(x-m+1):(x+1)]

    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        sr = s[::-1]
        l =  [0] * len(sr)*len(sr)
        for i in range(len(s)):
            for j in range(len(sr)):
                idx = i * len(s) + j
                if s[i] == sr[j]:
                    if i == 0 or j == 0:
                        l[idx] = 1
                    else:
                        l[idx] = l[idx-len(s)-1] + 1

        m=0
        x=-1
        for i in range(len(s)):
            for j in range(len(sr)):
                ind = i*len(s)+j
                if l[ind]>m:
                    m = l[ind]
                    x = i

        print x,m,s[(x-m+1):x+1]

if __name__ == "__main__":
    #print "abcabcbafggf"
    s="lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc"
    #s="ukxidnpsdfwieixhjnannbmtppviyppjgbsludrzdleeiydzawnfmiiztsjqqqnthwinsqnrhfjxtklvbozkaeetmblqbxbugxycrlzizthtuwxlmgfjokhqjyukrftvfwikxlptydybmmzdhworzlaeztwsjyqnshggxdsjrzazphugckgykzhqkdrleaueuajjdpgagwtueoyybzanrvrgevolwssvqimgzpkxehnunycmlnetfaflhusauopyizbcpntywntadciopanyjoamoyexaxulzrktneytynmheigspgyhkelxgwplizyszcwdixzgxzgxiawstbnpjezxinyowmqsysazgwxpthloegxvezsxcvorzquzdtfcvckjpewowazuaynfpxsxrihsfswrmuvluwbdazmcealapulnahgdxxycizeqelesvshkgpavihywwlhdfopmmbwegibxhluantulnccqieyrbjjqtlgkpfezpxmlwpyohdyftzgbeoioquxpnrwrgzlhtlgyfwxtqcgkzcuuwagmlvgiwrhnredtulxudrmepbunyamssrfwyvgabbcfzzjayccvvwxzbfgeglqmuogqmhkjebehtwnmxotjwjszvrvpfpafwomlyqsgnysydfdlbbltlwugtapwgfnsiqxcnmdlrxoodkhaaaiioqglgeyuxqefdxbqbgbltrxcnihfwnzevvtkkvtejtecqyhqwjnnwfrzptzhdnmvsjnnsnixovnotugpzuymkjplctzqbfkdbeinvtgdpcbvzrmxdqthgorpaimpsaenmnyuyoqjqqrtcwiejutafyqmfauufwripmpcoknzyphratopyuadgsfrsrqkfwkdlvuzyepsiolpxkbijqw"
    #s= "abcbade"
    #Solution().longestPalindrome("abcabcbaifggfi")
    Solution().longestPalindrome(s)
    Solution()._longestPalindrome(s)
