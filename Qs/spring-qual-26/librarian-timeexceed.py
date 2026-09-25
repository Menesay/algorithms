"""
5
3 7 2 5 4
6
1
3
4
10
12
21
"""
int_shelf_number = int(input())
int_book_number = list(map(int, input().split()))
int_query = int(input())
int_query_arr =[]

for i in range(int_query):
	int_query_arr.append(int(input()))

# int_query_arr = 1, 3 ,4 ,10,12,21
# int_book_number = 3 7 2 5 4
for q in int_query_arr:

	row = 1
	index = 1
	for book_i in int_book_number:
		if q-book_i > 0:
			row += 1

		if q-book_i <= 0:
			index = q
			break
		

		q = q-book_i

	print(row, index)


"""
length = 0
for i in range(int_shelf_number):
	length += int_book_number[i]
"""

"""
iota = []
for i in range(1,length+1):
	iota.append(i)
"""


# 4 querysi 2 rowda 1. index
# 10 querysi 2 rowda  7. index

"""
row tamam
for q in int_query_arr:

	row = 1
	for book_i in int_book_number:
		if q-book_i > 0:
			row += 1
		q = q-book_i

	print(row)
"""

"""

"""
