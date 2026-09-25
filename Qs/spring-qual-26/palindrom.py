
# 00:00:00 01:00:10

str_p = str(input())
str_p =str_p.replace(":", "")
#str_p = str_p.strip(" ")
#print(str_p)
t1 = []
t2 = []
for i in range(len(str_p[0:6])):
	t1.append(str_p[0:6][i])
for i in range(len(str_p[7:13])):
	t2.append(str_p[7:13][i])

# 10 dahil değil
#for i in range(1, 10):

# t1, t2 liste


def clock2second(clock):
	second = 0
	second += (int(clock[0])*10+int(clock[1]))*3600
	second += (int(clock[2])*10+int(clock[3]))*60
	second += (int(clock[4])*10+int(clock[5]))
	return second

def second2clock(second):

	clock = []
	hh=0
	mm = 0
	ss =0
	while (second >= 3600):
		hh += 1
		second = second- 3600
	while (second >= 60):
		mm += 1
		second = second- 60
	ss = second
	if hh > 9:
		clock.append(hh//10)
		clock.append(hh%10)
	else:
		clock.append(0)
		clock.append(hh)
	if mm > 9:
		clock.append(mm//10)
		clock.append(mm%10)
	else:
		clock.append(0)
		clock.append(mm)
	if ss > 9:
		clock.append(ss//10)
		clock.append(ss%10)
	else:
		clock.append(0)
		clock.append(ss)
		
	return clock


def palindrom(n: str):
    if n[0]==n[5] and n[1] == n[4] and n[2] == n[3] :
    	return True
    return False


t1_sec = clock2second(t1)
t2_sec = clock2second(t2)
sub = t2_sec - t1_sec

total = 0
for i in range(0, sub+1):
	if palindrom(second2clock(t1_sec+i)):
		total += 1
print(total)

"""
total = 0
for i in range(t1,t2):
	if palindrom(int(t1)+i) == True:
		total +=1


print(total)
"""