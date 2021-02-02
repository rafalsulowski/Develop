package interfejsy;


public class Pojazd {
    private double v_max;
    private int number;
    private String depotDesignation;  //nazwa zajezdni

    private static int nextId = 1001;


    public Pojazd(double v, int n, String str)
    {
        v_max = v;
        number = n;
        depotDesignation = str;

        nextId += 1000;
    }

    public Pojazd(double v, String str)
    {
        v_max = v;
        number = nextId;
        depotDesignation = str;

        nextId += 1000;
    }

    public Pojazd()
    {
        v_max = 0.0;
        number = nextId;
        depotDesignation = "Not assigned";

        nextId += 1000;
    }

    @Override
    public String toString()
    {
        return "Pojaz o numerze " + number +
                " rozwija predkosc maksymalną " + v_max +
                " km/h, garażuje w zajezdni " + depotDesignation;
    }

    public double getV_max() {
        return v_max;
    }

    public static int getNextId() {
        return nextId;
    }

    public int getNumber() {
        return number;
    }

    public String getDepotDesignation() {
        return depotDesignation;
    }

    public static void setNextId(int nextId) {
        Pojazd.nextId = nextId;
    }

    public void setDepotDesignation(String depotDesignation) {
        this.depotDesignation = depotDesignation;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public void setV_max(double v_max) {
        this.v_max = v_max;
    }
}
