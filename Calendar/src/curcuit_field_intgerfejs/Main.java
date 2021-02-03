package curcuit_field_intgerfejs;

import java.time.LocalDate;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<LocalDate> date = new ArrayList<>(12);

        for(int i = 1; i < 13; i++)
            date.add(LocalDate.of(2021, i, 15));

        for(LocalDate e : date)
        {
            System.out.println("\n\nMonth: " + e.getMonth());
            Main.showCalendar(e);
        }


    }

    public static void showCalendar(LocalDate date)
    {
        LocalDate tmp = date.minusDays(date.getDayOfMonth() - 1);
        int n = tmp.getDayOfWeek().getValue();

        System.out.println(" Pn  Wt  Śr  Cz  Pt  Sb  Nd");

        for(int i = 0; i < n - 1; i++)
            System.out.print("    ");

        int i = 1;
        for(; i <= 8 - n; i++)
        {
            if(i == date.getDayOfMonth())
                System.out.printf("%2d* ", i);
            else
                System.out.printf("%3d ", i);
        }

        for(int k = 0; i <= date.lengthOfMonth(); k++, i++) {
            if (i != 1 && k % 7 == 0)
                System.out.println();
            if (i == date.getDayOfMonth())
                System.out.printf("%3d*", i);
            else
                System.out.printf("%3d ", i);
        }
    }



}
