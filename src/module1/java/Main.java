import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        Code code = new Code(45);
        code._1();
        code._2();
        code._3();
        code.printText();
        new Code._4().sample1();
        new Code._4().display2();
        code._5();
        code._7();
        code._10();
    }
}

class ParentClass {
    void printText() {
        System.out.println("Printing text");
    }
}

class Code extends ParentClass {

    /*1. Write a java program that reads a line of integers and then displays
each integer and the sum of all the integers.(use String Tokenizer class of java.util) */
    public void _1() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter numerical(s):");
        String inputValue = scanner.nextLine();
        StringTokenizer stringTokenizer = new StringTokenizer(inputValue, " ");
        int sum = 0;
        while (stringTokenizer.hasMoreTokens()) {
            String currentToken = stringTokenizer.nextToken();
            int currentInteger = Integer.parseInt(currentToken);
            System.out.println(currentInteger);
            sum += currentInteger;
        }
        System.out.println("Sum = " + sum);
        scanner.close();
    }

    /*
    2. Write java programs that uses the following keyword i)this ii)super
    * */ int i;

    public Code(int i) {
        this.i = i;
    }

    public void _2() {
        System.out.println(this.i);
        super.printText();
    }

    /*
    3. Write java programs that uses the following keyword i) static ii)final

    - Final Classes: A final class cannot be subclassed. It is often used to prevent inheritance or extension of a class.
    - Final Methods: A final method in a class cannot be overridden by subclasses.
    - Final Variables: When a variable is declared as final, its value cannot be changed once assigned. It becomes a constant.
    - When a class is declared as final in Java, it means that it cannot be extended or subclassed. The final keyword, when applied to a class, method, or variable, serves as a modifier to indicate that it is not designed to be overridden, extended, or modified.
    * */
    public final void _3() {
        System.out.println("in a final function");
    }

    @Override
    protected void printText() {
        super.printText();
        System.out.println("In overriden function");
    }

    /*
    4. Write a java programs to implement multiple inheritance & program that uses access specifiers
    - Java doesn't support multiple inheritance through class inheritance, but it allows multiple inheritance through interfaces.
    * */
    interface Sample1 {
        void sample1();
    }

    interface Sample2 {
        void display2();
    }

    static class _4 implements Sample1, Sample2 {

        @Override
        public void sample1() {
            System.out.println("In sample1");
        }

        @Override
        public void display2() {
            System.out.println("In display2");
        }
    }

    /*
    5. Write a java program that reads a file and displays the file on the screen with a linenumber before each line.
    * */

    void _5() {
        String filePath = "singleLinkedList.txt";
        try {
            BufferedReader bufferReader = new BufferedReader(new FileReader((filePath)));
            String currentLine = bufferReader.readLine();
            int currentLineNo = 1;

            while (currentLine != null) {
                System.out.println(currentLineNo + " " + currentLine);
                currentLine = bufferReader.readLine();
                currentLineNo++;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    /*
    7. Write a java program that displays the number of characters,lines and words in a text file.
    * */

    void _7() {
        String filePath = "singleLinkedList.txt";

        int totalLineNo = 0;
        int totalCharNo = 0;
        int totalWords = 0;
        try {
            BufferedReader bufferedReader = new BufferedReader((new FileReader(filePath)));
            String currentLine = bufferedReader.readLine();
            while (currentLine != null) {
                String[] words = currentLine.split("\\+s");
                totalWords += words.length;
                totalCharNo += currentLine.length();
                totalLineNo++;
                currentLine = bufferedReader.readLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("lines = " + totalLineNo);
        System.out.println("char = " + totalCharNo);
        System.out.println("words = " + totalWords);
    }

    /*
    10. Write a java program that creates three threads. first thread displays “good morning” every one second.
    * */

    void _10() {
        Thread thread1 = new Thread(() -> {
            while (true) {
                System.out.println("good morning");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        Thread thread2 = new Thread(() -> {
            try {
                System.out.println("one");
                Thread.sleep(1000);
                System.out.println("two");
                Thread.sleep(1000);
                System.out.println("three");
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread thread3 = new Thread(() -> {
            try {
                System.out.println("four");
                Thread.sleep(1000);
                System.out.println("five");
                Thread.sleep(1000);
                System.out.println("six");
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        thread1.start();
        thread2.start();
        thread3.start();
    }
}