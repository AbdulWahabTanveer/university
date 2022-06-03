import random

def FitnessFuntion(currentQueenList):
    CurrentQueenPlace = -1
    FitnessValue = 8
    inDanger = False

    for columQueenPlace in currentQueenList:
        CurrentQueenPlace += 1
        for horQueenPlace_1 in range(CurrentQueenPlace+1, 8):
            if(currentQueenList[horQueenPlace_1] == columQueenPlace):
                inDanger = True
        for horQueenPlace_2 in reversed(range(0, CurrentQueenPlace)):
            if(horQueenPlace_2 < 0):
                continue
            if(currentQueenList[horQueenPlace_2] == columQueenPlace):
                inDanger = True
        if(inDanger):
            inDanger = False
            #print("inDanger due to same position",CurrentQueenPlace)
            FitnessValue = FitnessValue-1
        else:
            diagUpCounter = 0
            diagDownCounter = 0
            for diagQueenPlace_1 in range(CurrentQueenPlace+1, 8):
                # print(diagQueenPlace_1)
                diagUpCounter = diagUpCounter+1
                diagDownCounter = diagDownCounter-1

                if(currentQueenList[diagQueenPlace_1] == columQueenPlace+diagUpCounter or currentQueenList[diagQueenPlace_1] == columQueenPlace+diagDownCounter):
                    inDanger = True
            diagUpCounter = 0
            diagDownCounter = 0
            for diagQueenPlace_2 in reversed(range(0, CurrentQueenPlace)):
                if(diagQueenPlace_2 < 0):
                    continue
                diagUpCounter = diagUpCounter+1
                diagDownCounter = diagDownCounter-1
                if(currentQueenList[diagQueenPlace_2] == columQueenPlace+diagUpCounter or currentQueenList[diagQueenPlace_2] == columQueenPlace+diagDownCounter):
                    inDanger = True
        if(inDanger):
            #print("inDanger due to diag ",CurrentQueenPlace)
            inDanger = False
            FitnessValue = FitnessValue-1
    return FitnessValue


# Main Code

#prep
Queens_1 = []
Queens_2 = []
crossover_1 = []
crossover_2 = []

for i in range(8):
    Queens_1.append(random.randint(1, 8))
    Queens_2.append(random.randint(1, 8))
    crossover_1.append(random.randint(1, 8))
    crossover_2.append(random.randint(1, 8))

#main Loop
for iterations in range(1000):

    print("\n")
    print("Working for a List ", Queens_1)
    Fit1 = FitnessFuntion(Queens_1)
    print(Fit1)

    print("Working for a List ", Queens_2)
    Fit2 = FitnessFuntion(Queens_2)
    print(Fit2)

    print("Working for a List ", crossover_1)
    Fit3 = FitnessFuntion(crossover_1)
    print(Fit3)

    print("Working for a List ", crossover_2)
    Fit4 = FitnessFuntion(crossover_2)
    print(Fit4)

    best1 = Fit1
    best2 = Fit2
    temp1= Queens_1
    temp2= Queens_2
    isneeded = True

    if(Fit1==8):
        print("Hurray we Got it! in ",iterations,Queens_1)
        exit(0)

    if(Fit2==8):
        print("Hurray we Got it! in ",iterations,Queens_2)
        exit(0)

    if(Fit3==8):
        print("Hurray we Got it! in ",iterations,crossover_1)
        exit(0)

    if(Fit4==8):
        print("Hurray we Got it! in ",iterations,crossover_2)
        exit(0)


    if(Fit3>best1 and isneeded):
        isneeded=False
        if(best1>best2):
            temp2=crossover_1.copy()
        else:
            temp1=crossover_1.copy()

    if(Fit3>best2 and isneeded):
        temp2=crossover_1.copy()
    
    isneeded=True
    
    if(Fit4>best1 and isneeded):
        isneeded=False
        if(best1>best2):
            temp2=crossover_2.copy()
        else:
            temp1=crossover_2.copy()
    if(Fit4>best2 and isneeded):
        temp2=crossover_1

    Queens_1=temp1.copy()
    Queens_2=temp2.copy()

    temp3=[]
    temp4=[]
    # CrossOver
    for i in range(4):
        temp3.append(Queens_1[i])
    for i in range(4):
        temp4.append(Queens_2[i])
    for i in range(4,8):
        temp3.append(Queens_2[i])
    for i in range(4,8):
        temp4.append(Queens_1[i])
        
    # Mutation
    temp3[random.randint(0, 7)] = random.randint(1, 8)
    temp4[random.randint(0, 7)] = random.randint(1, 8)

    crossover_1=temp3.copy()
    crossover_2=temp4.copy()

    #after every iteration showing result
    print(Queens_1,Queens_2,crossover_1,crossover_2)




