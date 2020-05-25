for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    temp=[]
    for i in a[::-1]:
        if i >k:
            temp.append(a.pop(-1))
        else:
            break

    for i in range(0,len(temp)-1):
        temp[i+1]-=temp[i]-k
        temp[i]=k
 
    print(sum(a)+sum(temp))
