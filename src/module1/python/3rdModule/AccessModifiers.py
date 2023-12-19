"""
Encapsulation is an OOPs principle which protects the internal data of the class using Access modifiers like Public,Private and Protected.
"""

"""
1. By default the member variables and methods are public which means they can be accessed from anywhere outside or inside the class. No public keyword is required to make the class or methods and properties public.
Example:
"""
class Sample:
    def publicFunction(self,age):
        print(str(age))

sample = Sample()
sample.publicFunction(age=450) # 450   

"""
Private Access Modifier:
- private properties and methods are declared by adding a prefix with two underscores("__")
"""   
class PrivateAccessModifier:
    def __privateFunction(self):
        print("this is a private function")
    def publicFunction(self):
        print("this is a public function")

privateAccessModifier = PrivateAccessModifier()
privateAccessModifier.publicFunction() # will print "this is a public function"
# privateAccessModifier.__privateFunction() # will throw "AttributeError"                

"""
Protected Access Modifier:
- Class properties and methods with protected access modifier can be accessed within the class and from the class that inherits the protected class.
- If a developer chooses to access a method with a single underscore from outside the class, Python won't raise an error.
"""

class ProtectedAccessModifier:
    def publicFunction(self):
        print("public function")
    
    def _protectedFunction(self):
        print("protected function")


class NonInheritedClass:
    def printData(self):
        protectedAccessModifier = ProtectedAccessModifier()
        protectedAccessModifier.publicFunction()
        protectedAccessModifier._protectedFunction()
        
class ChildInheritedClass(ProtectedAccessModifier):
    def __init__(self):
        super()._protectedFunction() # protected function
        super().publicFunction() # public function  
        
    def __str__(self):
        return "in a child class"             

childInheritedClass = ChildInheritedClass()
nonInheritedClass = NonInheritedClass()
nonInheritedClass.printData()
print(childInheritedClass) # in a child class