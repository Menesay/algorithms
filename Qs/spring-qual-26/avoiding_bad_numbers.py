int_arr = list(map(int, input().split()))

l = int_arr[0]
r = int_arr[1]


def is_good(n : int):
	if n % 2 == 0:
		return False
	if n % 3 == 0:
		return False	
	if n % 5 == 0:
		return False
	if n % 7 == 0:
		return False		
	return True 

total =0


if l % 2 == 0:
	# l+1 den 
	ite = 0
	for i in range(l+1, r, 2):
		if is_good(l+ite):
			total +=1
		ite += 2

print(total)