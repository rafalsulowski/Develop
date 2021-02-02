package interfejsy;

import java.util.ArrayList;

public class ZajezdniaAutobusowa{
    private String designation;     //designation ->nazwa
    private ArrayList<Autobus> vehicles;

    public ZajezdniaAutobusowa(String n, ArrayList<Autobus> arr)
    {
        designation = n;
        vehicles = arr;
    }
    public ZajezdniaAutobusowa(String n)
    {
        designation = n;
        vehicles = new ArrayList<Autobus>();
    }

    public ZajezdniaAutobusowa()
    {
        designation = "";
        vehicles = new ArrayList<Autobus>();
    }

    public String getDesignation() {
        return designation;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public ArrayList<Autobus> getVehicles() {
        return vehicles;
    }

    public void addVehicle(Autobus v)
    {
        vehicles.add(v);
    }

    private double getMediumFuelConsumption()
    {
        double sum = 0;

        for(Autobus e : vehicles)
            sum += e.getFuelConsumption();

        return sum;
    }



    @Override
    public String toString() {
        return "Zajezdnia Autobusowa o nazwie " + designation + " garażuje " + vehicles.size() +
                " autobusów, które spalają łącznie (średnio): " + getMediumFuelConsumption() +
                " litów paliwa, oto one: " + vehicles.toString();
    }


}
