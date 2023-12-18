import copy
"""
Simple example:

The self parameter is a reference to the current instance of the class, and is used to access variables that belongs to the class.

It does not have to be named self , you can call it whatever you like, but it has to be the first parameter of any function in the class:
"""
class SampleClass:
    i = 0
    
    def sampleFunction(self,value): # "self" is a default param
        print(value+value)

sampleClass = SampleClass()
sampleClass.i = 45 # objects are mutable
sampleClass.sampleFunction(value=45) #90
# used named param
print(sampleClass.i) # 45

"""
Output:
90
45
"""


"""
with __init__():
The __init__() function is called automatically every time the class is being used to create a new object.
"""

class ClassUsingInitBlock:
    def __init__(self,age,name):
        self.nameOfThePerson = name
        self.ageOfThePerson = age
        print("executing from __init__ block")

classUsingInitBlock = ClassUsingInitBlock(name = "Sample Name", age = 100)
print("age of the person is {}".format(classUsingInitBlock.ageOfThePerson))        
print("name of the person is {}".format(classUsingInitBlock.nameOfThePerson))        
"""
Output: 
executing from __init__ block
age of the person is 100
name of the person is Sample Name
"""

"""
with __str__() Function
The __str__() function controls what should be returned when the class object is represented as a string.
"""
class ClassUsingSTR():
    def __init__(self,name,age):
        self.nameOfThePErson = name
        self.ageOfThePerson = age
    
    def __str__(self): # when calling objects in print(), the following string will be returned and printed.
        return "Name of the person : {}\nAge of the person : {}".format(self.nameOfThePErson, self.ageOfThePerson)    

classUsingSTR = ClassUsingSTR(age=100,name="sample text")
sampleCopy = copy.copy(classUsingSTR)
print("printing from copied object ->\n{}".format(sampleCopy))
print("printing using original object -> \n"+str(classUsingSTR)) # there is no need to call variables and then format them as strings, as __str__ is a string when this object is created.
"""
Output:
printing from copied object ->
Name of the person : sample text
Age of the person : 100
printing using original object ->
Name of the person : sample text
Age of the person : 100
"""

"""
1. can delete properties on objects by using the del keyword
del p1.age

2. can delete objects by using the del keyword:
del p1

3. class definitions cannot be empty, but if you for some reason have a class definition with no content, put in the pass statement to avoid getting an error.
class Person:
  pass
"""