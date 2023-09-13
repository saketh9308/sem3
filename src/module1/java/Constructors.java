package module1.java;

public class Constructors {
    int _no;
    String _name;

    public Constructors(int no, String name) {
        _no = no;
        _name = name;
    }

    public static void main(String args[]) {
        Constructors constructors = new Constructors(0, "sample text");
        System.out.println(constructors._name + "\n" + constructors._no);
    }
}

/**

Output:
sample text
0

*/
