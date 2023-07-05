class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if (s[0] == '0'):
            return 0

        if (length == 1):
            return 1

        tab = [0] * length
        tab[0] = 1
        ones = int(s[1])
        tens = int(s[0] + s[1])
        if (ones >= 1):
            tab[1] += 1
        
        if (tens >= 10 and tens <= 26):
            tab[1] += 1 
        
        for idx in range(2, length):
            ones =int(s[idx])
            if (ones >= 1):
                tab[idx] += tab[idx-1]

            tens = int(s[idx-1] + s[idx])
            if (tens >= 10 and tens <= 26):
                tab[idx] += tab[idx-2]
        
        return tab[length-1]