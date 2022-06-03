currentQueenList = [4, 8, 1, 5, 7, 2, 6, 3]

FitnessValue =

for columQueenPlace in currentQueenList:
    CurrentQueenPlace+=1
            for horQueenPlace_1 in range(CurrentQueenPlace+1,8):
                if(currentQueenList[horQueenPlace_1]==columQueenPlace):
                    inDanger=True
            for horQueenPlace_2 in reversed(range(0,CurrentQueenPlace)):
                if(horQueenPlace_2<0):
                    continue
                if(currentQueenList[horQueenPlace_2]==columQueenPlace):
                    inDanger=True
            if(inDanger):
                inDanger=False
                #print("inDanger due to same position",CurrentQueenPlace)
                FitnessValue=FitnessValue-1
            else:
                diagUpCounter = 0 
                diagDownCounter = 0 
                for diagQueenPlace_1 in range(CurrentQueenPlace+1,8):
                    #print(diagQueenPlace_1)
                    diagUpCounter=diagUpCounter+1
                    diagDownCounter=diagDownCounter-1
                
                    if(currentQueenList[diagQueenPlace_1]==columQueenPlace+diagUpCounter or currentQueenList[diagQueenPlace_1]==columQueenPlace+diagDownCounter):
                        inDanger=True
                diagUpCounter = 0 
                diagDownCounter = 0 
                for diagQueenPlace_2 in reversed(range(0,CurrentQueenPlace)):
                    if(diagQueenPlace_2<0):
                        continue
                    diagUpCounter=diagUpCounter+1
                    diagDownCounter=diagDownCounter-1
                    if(currentQueenList[diagQueenPlace_2]==columQueenPlace+diagUpCounter or currentQueenList[diagQueenPlace_2]==columQueenPlace+diagDownCounter):
                        inDanger=True
            if(inDanger):
                #print("inDanger due to diag ",CurrentQueenPlace)
                inDanger=False
                FitnessValue=FitnessValue-1
    print(FitnessValue)