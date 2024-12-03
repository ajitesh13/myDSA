def partition(arr, l, r):
    pivot = arr[r]
    i = l
    for j in range(l, r):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i

def quick_select(arr, l, r, k):
    pivot = partition(arr, l, r)
    if pivot < k - 1:
        return quick_select(arr, pivot + 1, r, k)
    elif pivot > k - 1:
        return quick_select(arr, l, pivot - 1, k)
    else:
        return arr[pivot]

k = 1
arr = [1, 2, 3]
kth_element = quick_select(arr, 0, 2, k)
print(kth_element)
