int_arr = list(map(int, input().split()))

l = int_arr[0]
r = int_arr[1]


def is_good(n : int):

	return n % 2 != 0 and n % 3 != 0 and n % 5 != 0 and n % 7 != 0 

total =0
ite = 0
for i in range(l,r):
	if is_good(l+ite):
		total +=1

	ite +=1

print(total)