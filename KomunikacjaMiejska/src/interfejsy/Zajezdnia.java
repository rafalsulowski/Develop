package interfejsy;

import java.util.ArrayList;

public class Zajezdnia {
    private String designation;     //designation ->nazwa
    private ArrayList<Pojazd> vehicles;

    public Zajezdnia(String n, ArrayList<Pojazd> arr)
    {
        designation = n;
        vehicles = arr;
    }
    public Zajezdnia(String n)
    {
        designation = n;
        vehicles = new ArrayList<Pojazd>();
    }

    public Zajezdnia()
    {
        designation = "";
        vehicles = new ArrayList<Pojazd>();
    }

    public String getDesignation() {
        return designation;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public ArrayList<Pojazd> getVehicles() {
        return vehicles;
    }

    public void addVehicle(Pojazd v)
    {
        vehicles.add(v);
    }

    @Override
    public String toString() {
        return "Zajezdnia o nazwie " + designation + " garażuje " + vehicles.size() + " pojazdow, oto one: " + vehicles.toString();
    }
}
