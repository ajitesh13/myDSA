def solve():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])  # Number of test cases
    result = []
    idx = 1

    for _ in range(t):
        n = int(data[idx])  # Length of the array
        a = list(map(int, data[idx + 1].split()))  # The array
        idx += 2
        
        if n == 2:
            # Always YES for n=2
            result.append("YES")
            continue
        
        # Sort the array to check the largest three elements
        a.sort()
        
        # Check the triangle inequality for the last three elements
        if a[-3] + a[-2] > a[-1]:
            result.append("YES")
        else:
            result.append("NO")
    
    # Print all results at once
    sys.stdout.write("\n".join(result) + "\n")
