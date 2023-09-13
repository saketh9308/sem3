package module1.java; // this isn't linked with following code context

public class Arrays {
    public static void main(String[] args) {

        int[] _int = {1, 2};
        //or
        String[] statsRanking = {"Drake", "Kanye"};

        _int[0] = 2;
        statsRanking[0] = statsRanking[1];
        statsRanking[1] = "Drake";

        System.out.println(_int[0]);

        for (int i = 0; i < 2; i++) {
            System.out.println(statsRanking[i]);
        }

    }
}

/*

Output:
2
Kanye
Drake

* */