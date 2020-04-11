fin = open("wcal.in","r")

#tc = int(input())
tc = int(fin.readline())
for k, e in enumerate(range(tc), 1):
    #Num = int(input())
    Num = int(fin.readline())
    N = list(map(int, str(Num)))
    r = list(range(0, 9, 2))
    temp1 = N[:]
    temp2 = N[:]
    flag_odd = 0
    flag_add=0
    if N[0]%2 == 0:
        # print("first even")
        for i in range(1, len(N)):
            # print("i : ",N[i])
            # print("temp : ",temp1)
            if flag_odd == 1:
                temp1[i] = 0
                temp2[i] = 8

            if N[i]%2 != 0 and flag_odd == 0:
                # print("found odd")
                if N[i] == 9:
                    temp1[i] = 0
                    temp2[i] -= 1
                    j = i-1
                    if temp1[j] < 8:
                        temp1[i-1] += 2
                    elif temp1[j] == 8:
                        # print("found 8")
                        while temp1[j] == 8:
                            # print("chainginf temp : ",temp1)
                            temp1[j] = 0
                            j -= 1
                        if j >= 0:
                            temp1[j] += 2 
                        else:
                            flag_add=1
                else:
                    temp1[i] += 1
                    temp2[i] -= 1 
                # print("folg odd set to 1")
                flag_odd = 1
        if flag_add == 1:
            temp1 = [2] + temp1  
        
    else:
        if N[0] < 9:
            temp1[0] += 1
        else:
            temp1[0] = 20
        temp2[0] -= 1
        for i in range(1, len(N)):
            # print("temp1 : ",temp1)
            if N[i] == 9:
            
                temp1[i] = 0
                temp2[i] -= 1
                j = i-1
                if temp1[j] < 8:
                    temp1[i-1] += 2
                else:
                    while temp1[j] == 8:
                        temp1[j] = 0
                        j -= 1
            else:
                temp1[i] = 0
                temp2[i] = 8

    inr = int("".join([str(x) for x in temp1]))
    dcr = int("".join([str(x) for x in temp2]))
    # print("inr : ",inr)
    # print("dcr : ",dcr)
    if inr-Num > Num-dcr:
        min_steps = Num-dcr
    else:
        min_steps = inr-Num
    
    print("case#",k," : ",min_steps)


    
