package module1.java;

public class ClassAndMethods {
    int i = 3;
    String name = "sample text";

    public static void printExistingName() {
        ClassAndMethods classInstance = new ClassAndMethods();
        System.out.println(classInstance.name);
    }

    public static void main(String[] args) {

        printExistingName();
        //or
        ClassAndMethods.printExistingName();

        ClassAndMethods classInstance = new ClassAndMethods();
        float newValue = classInstance.halfOfTheExistingValue(classInstance.i);
        System.out.println(newValue);

    }

    public float halfOfTheExistingValue(float existingValue) {
        return existingValue / 2;
    }
}

/*

Output:
sample text
sample text
1.5

*/
