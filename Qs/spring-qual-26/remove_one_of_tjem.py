
int_n = int(input())
int_arr = list(map(int, input().split()))

sum=0

for i in range(int_n):
    sum += int_arr[i]

new_sums= []
for i in range(int_n):

    new_sums.append(abs(sum-int_arr[i]))

print(min(new_sums))