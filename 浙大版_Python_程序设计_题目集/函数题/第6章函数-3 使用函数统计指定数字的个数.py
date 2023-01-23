# https://pintia.cn/problem-sets/1111652100718116864/problems/1163035698160459778
def CountDigit(number, digit):
	if number < 0:
		number = -number
	cnt = 0
	while number != 0:
		if (number % 10 == digit):
			cnt += 1
		number //= 10
	return cnt