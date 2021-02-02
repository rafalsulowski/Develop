package interfejsy;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        ArrayList<Autobus> tab = new ArrayList<>(4);
        tab.add(new Autobus(15.5, 110.0, 1001, "Tatary"));
        tab.add(new Autobus(16.5, 111.0, 2001, "Tatary"));
        tab.add(new Autobus(17.5, 109.0, "Wigry"));
        tab.add(new Autobus(14.5, 113.0, "Tatary"));

        ZajezdniaAutobusowa zajezdniaautobusowa = new ZajezdniaAutobusowa("Tatary");
        for(Autobus e : tab)
            if(e.getDepotDesignation().equals(zajezdniaautobusowa.getDesignation()))
                zajezdniaautobusowa.addVehicle(e);

        System.out.println(zajezdniaautobusowa.toString());

        ArrayList<Autobus> tab_autobusy = new ArrayList<>();
        tab_autobusy.add(new Autobus(20.5, 78.9, "Wigry"));
        tab_autobusy.add(new Autobus(21.5, 80.9, "Wigry"));
        tab_autobusy.add(new Autobus(23.5, 83.9, "Wigry"));
        tab_autobusy.add(new Autobus(21.5, 79.9, "Wigry"));
        tab_autobusy.add(new Autobus(27.5, 72.9, "Wigry"));
        tab_autobusy.add(new Autobus(25.5, 74.9, "Wigry"));
        tab_autobusy.add(new Autobus(23.5, 76.9, "Wigry"));

        ZajezdniaAutobusowa zajezdnia2 = new ZajezdniaAutobusowa("Wigry", tab_autobusy);
        zajezdnia2.addVehicle(tab.get(2));

        System.out.println(zajezdnia2.toString());

        //testy zajezdni tramwajowej:

        ZajezdniaTramwajowa zajezdniatramwajowa = new ZajezdniaTramwajowa("Kabaty");

        ArrayList<Tramwaj> tramwaje = new ArrayList<>();
        tramwaje.add(new Tramwaj(3, 56.6, "Kabaty"));
        tramwaje.add(new Tramwaj(2, 57.6, "Kabaty"));
        tramwaje.add(new Tramwaj(3, 59.6, "Kabaty"));
        tramwaje.add(new Tramwaj(2, 54.6, "Kabaty"));
        tramwaje.add(new Tramwaj(1, 51.6, "Kabaty"));

        for(Tramwaj p : tramwaje)
            if(p.getDepotDesignation().equals(zajezdniatramwajowa.getDesignation()))
                zajezdniatramwajowa.addVehicle(p);

        System.out.println(zajezdniatramwajowa.toString());

        ArrayList<Tramwaj> tramwaj2 = new ArrayList<>();
        tramwaj2.add(new Tramwaj(3, 43.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(2, 45.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(3, 47.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(3, 40.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(2, 42.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(1, 43.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(1, 49.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(1, 44.2, "Miłocin"));
        tramwaj2.add(new Tramwaj(1, 47.2, "Miłocin"));

        ZajezdniaTramwajowa t3 = new ZajezdniaTramwajowa("Miłocin", tramwaj2);

        System.out.println(t3.toString());





    }
}



