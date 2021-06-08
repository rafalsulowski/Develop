package MorsCode;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        MorsCode code = new MorsCode();

        String str = in.nextLine();
        code.translate(str);
    }
}
