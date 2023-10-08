# eg 1
start  =1
until = 5
i=range(start,until)
print(5 in i) #False

# eg 2
inputValue  = int(input("Enter your marks:"))

if(inputValue in range(0,34)):
    print("FAIL")
elif (inputValue in range(35,50)):
    print("C Grade")
elif (inputValue in range(50, 65)):
    print("B Grade")
elif (inputValue in range(65,85)):
    print("A Grade")
elif(inputValue in range(85,100)):
    print("O Grade")
else :
    print("Sup")

# eg 3

for num in range(0,4):
    print(num)

# eg 4

def repeat():
    return ("🤨")
    
for _ in range(0,4):
    print(repeat())

# eg 5

i = list(range(0,5,2))
print(i) # [0, 2, 4]