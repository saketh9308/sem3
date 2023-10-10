# eg1
def printTxt():
    print("Sample Text")


printTxt()
"""
Sample Text
"""


# eg2
def returnValue(value):
    return "given value is: " + str(value)


i = returnValue(15)
print(i)
"""
given value is: 15
"""


# eg 3
def no(age, name1="text", **sample):
    for key, value in sample.items():
        print("key = {} and value = {}".format(key, value))


no(45, name="saketh", yerye="yeye")
"""
Variable-Length Positional Parameters (*args): These parameters allow you to accept any number of positional arguments. They come after regular parameters.
Example: def function_name(param1, param2, *args):
key = name and value = saketh
key = yerye and value = yeye
"""

#eg 4
def sampleFunction(age, *hobbies, name="sample Text"):
    for i in hobbies:
        print(i)
    print("name is " + name + ", age is " + str(age))


sampleFunction(45, *[1,2,3,4,5])
"""
Variable-Length Keyword Parameters (**kwargs): These parameters allow you to accept any number of keyword arguments. They come after regular and variable-length positional parameters.
Example: def function_name(param1, param2, *args, **kwargs):
1
2
3
4
5
name is sample Text, age is 45
"""