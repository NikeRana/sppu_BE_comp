def fibonacci_nonRecursive(n):
    if n<=1:
        return n
    else:
        a, b = 0,1
        for _ in range (2,n+1):
            a,b = b, a+b
        return b
    
def fibonacci_recursive(n):
    if n<=1:
        return n
    else:
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
    

num = int(input("Enter you number "))
print("fibonacci number using non recursive appraoch ")
print(fibonacci_nonRecursive(num))
print("fibonacci number using recursive appraoch ")
print(fibonacci_recursive(num))

"""
time complexity: 
1. non recursive: O(n)
2. recursive: O(2^n)

space complexity:
1. non recursive: O(1)
2. recursive: O(n)
"""