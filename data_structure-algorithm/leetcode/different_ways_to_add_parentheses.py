import re

class Solution:
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):

        nums = [ int(nu) for nu in re.findall('[\w]+',input) ]
        ops = re.findall('[-+*]',input)

        def eval(x,y,op):
            if op == '-':
                return x-y
            elif op == '+':
                return x+y
            else:
                return x*y

        m = {}
        size = len(nums)

        for s in range(0,size):
            m[s] = {}
            m[s][s] = [nums[s]]

        for l in range(2,size+1):
            for s in range(size-l+1):
                e = s+l-1
                m[s][e] = []
                for k in range(s,e):
                    for x in m[s][k]:
                        for y in m[k+1][e]:
                            m[s][e] +=[eval(x,y,ops[k])]
        print m[0][size-1]
        return m[0][size-1]

if __name__ == "__main__":
    s = Solution()
    s.diffWaysToCompute("2-1-1")
    s.diffWaysToCompute("2*3-4*5")
    #s.diffWaysToCompute("2*3-4*5")


