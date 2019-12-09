import threading
import numpy as np

n = int(input("Enter the number: "))
fib = np.zeros(n, dtype=int)

def runn(num):
	if num == 0:
		fib[num] = 0
	if num == 1:
		fib[num] = 1
	else:
		fib[num] = fib[num-1] + fib[num-2]

if __name__ == "__main__":
	for i in range(n):
		t1 = threading.Thread(target=runn, args=(i,))
		t1.start()
		t1.join()
	print("Fibonacci Sequence:",fib)