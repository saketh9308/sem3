package module1.java;

import java.util.Scanner;

public class ControlStatements {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter a numerical : ");
        int i = input.nextInt();

        if (i < 45) {
            System.out.println("<45");
        } else if (i == 45) {
            System.out.println("45");
        } else {
            System.out.println(">45");
        }

        switch (i) {
            case 20:
                System.out.println("20");
            case 30:
                System.out.println("30");
            case 40:
                System.out.println("40");
            default:
                System.out.println("\"All My Demons Getting Me As A Friend\" clears your fav album.");
        }
    }
}


/*


Output:-
Enter a numerical : 40
<45
40
"All My Demons Getting Me As A Friend" clears your fav album.

*/
