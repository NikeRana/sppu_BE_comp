import random

# Partition using the last element as the pivot
def deterministicPartition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Randomized partition
def randomizedPartition(arr, low, high):
    random_index = random.randint(low, high)
    arr[random_index], arr[high] = arr[high], arr[random_index]
    return deterministicPartition(arr, low, high)

def deterministicQuickSort(arr, low, high):
    if low < high:
        pi = deterministicPartition(arr, low, high)
        deterministicQuickSort(arr, low, pi - 1)
        deterministicQuickSort(arr, pi + 1, high)

def randomizedQuickSort(arr, low, high):
    if low < high:
        pi = randomizedPartition(arr, low, high)
        randomizedQuickSort(arr, low, pi - 1)
        randomizedQuickSort(arr, pi + 1, high)

if __name__ == "__main__":
    arr = []
    num = int(input("Enter the number of elements:"))
    for _ in range(num):
        n = int(input("Enter an element:"))
        arr.append(n)
    
    n = len(arr)

    deterministicQuickSort(arr, 0, n - 1)
    print("Sorted array using deterministic quicksort:")
    for i in range(n):
        print(arr[i], end=" ")
    print()

    arr = [10, 7, 8, 9, 1, 5]
    randomizedQuickSort(arr, 0, n - 1)
    print("Sorted array using randomized quicksort:")
    for i in range(n):
        print(arr[i], end=" ")
    print()


"""
time complexity: 
1. Deterministic Quicksort: pivot selection always chooses the smallest or largest element, O(n^2)
2. Randomized Quicksort: pivot selection makes the worst-case scenario , O(n * log(n))

space complexity:
O(log(n)) because of the recursive function call stack.
"""