
"""
str_arr = []
for i in range(n):
    str_arr.append(str(input()))

def operator_counts(lines: str):
    ops = "+-*:"
    result = []
    
    for line in lines:
        count = 0
        for c in line:
            if c in ops:
                count += 1
        result.append(count)
    
    return sorted(result)

# ilk test case için
# sorted_arr = [1, 2, 2, 3, 4]


sorted_arr = operator_counts(str_arr)

def remove_duplicates(lst):
    new_list = []
    for i in lst:
        if i not in new_list:
            new_list.append(i)
    return new_list

last_arr = remove_duplicates(sorted_arr)
last_arr_len = last_arr.len()
"""

int_arr = list(map(int, input().split()))
n = int_arr[0]
k = int_arr[1]


str_arr = []
for i in range(n):
    str_arr.append(str(input()))

def operator_counts(lines):
    ops = "+-*:"
    result = []
    
    for line in lines:
        count = 0
        for c in line:
            if c in ops:
                count = count + 1
        result.append(count)
    
    return result



ops_arr = operator_counts(str_arr)

dp = []
for i in range(n):

    row = []

    for j in range(k + 1):
        row.append(0)



    dp.append(row)

for i in range(n):
    dp[i][1] = 1

for i in range(n):
    for j in range(i):
        if ops_arr[j] < ops_arr[i]:
            for length in range(1, k):
                dp[i][length + 1] = dp[i][length + 1] + dp[j][length]

result = 0

for i in range(n):
    result = result + dp[i][k]

if result == 0:
    print(-1)
else:
    print(result)

