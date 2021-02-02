package interfejsy;

import java.util.ArrayList;

public class ZajezdniaTramwajowa {
    private String designation;     //designation ->nazwa
    private ArrayList<Tramwaj> vehicles;

    public ZajezdniaTramwajowa(String n, ArrayList<Tramwaj> arr)
    {
        designation = n;
        vehicles = arr;
    }
    public ZajezdniaTramwajowa(String n)
    {
        designation = n;
        vehicles = new ArrayList<Tramwaj>();
    }

    public ZajezdniaTramwajowa()
    {
        designation = "";
        vehicles = new ArrayList<Tramwaj>();
    }

    public String getDesignation() {
        return designation;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public ArrayList<Tramwaj> getVehicles() {
        return vehicles;
    }

    public void addVehicle(Tramwaj v)
    {
        vehicles.add(v);
    }

    private int getSumofStaff()
    {
        int sum = 0;

        for(Tramwaj e : vehicles)
            sum += e.getStaff();

        return sum;
    }


    @Override
    public String toString() {
        return "Zajezdnia tramwajowa o nazwie " + designation + " garażuje "
                + vehicles.size() + " tramwaji o łącznej sumie wagonów: "
                + getSumofStaff() + ", oto one: " + vehicles.toString();
    }
}