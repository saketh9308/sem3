# eg1

def sample(num):
    if(num<6):
        print(num)
        num+=1
        sample(num)
        
i=1
sample(i)
"""
1
2
3
4
5
"""

# fib
def fib(num):
    if num<=1:
        return num
    else:
        return fib(num-1)+fib(num-2)

for num in range(5):
    print(fib(num))
"""
0
1
1
2
3
"""