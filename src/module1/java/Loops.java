package module1.java;

public class Loops {

    int _int = 0;
    String[] _string = {"sample num = " + _int++, "sample num = " + _int++, "sample num = " + _int++, "sample num = " + _int++, "sample num = " + _int++, "sample num = " + _int++};

    public static void main(String[] args) {

        Loops loops = new Loops();
        for (int i = 0; i < loops._string.length; i++) {
            System.out.println(loops._string[i]);
        }

        int i = 0;
        while (i < 6) {
            i++;
            System.out.println(i);
        }

        int j = 0;
        do {
            System.out.println("!1");
        } while (j == 1);

    }
}


/*

Output:

sample num = 0
sample num = 1
sample num = 2
sample num = 3
sample num = 4
sample num = 5
1
2
3
4
5
6
!1

* */