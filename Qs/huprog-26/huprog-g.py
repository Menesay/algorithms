
str_input = str(input())
# Oo, it aaa is not bb.


"""
def sanitize(s: str):
    chars = ['.', ',', ';', ':', '!', '?', '(', ')', '"',  '-', "'","`"]
    
    for c in chars:
        s = s.replace(c, "")
    return s

"""

alfabe = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "

str_new = ""
for letter in str_input:
    if letter in alfabe:
        str_new += letter



arr = str_new.split()


# arr  = ['Oo', 'it', 'aaa', 'is', 'not', 'bb']


def pal(s):

    s = s.lower()
    if s == s[::-1]:
        return True
    return False

"""
    for i in range(len(s)//2):
        if s[i] != s[-i-1]:
            return False
    return True
"""
MAX=0
result=0

# arr  = ['Oo', 'it', 'aaa', 'is', 'not', 'bb']

for e in range(len(arr)):
    if pal(arr[e]) and len(arr[e]) > MAX:
        MAX=len(arr[e])
        result=e

 

print(result+1)