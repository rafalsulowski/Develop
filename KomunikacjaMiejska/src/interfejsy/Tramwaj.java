package interfejsy;

public class Tramwaj extends Pojazd{
    private int staff; //range 1-3

    public Tramwaj(int st, double v, int n, String str)
    {
        super(v, n, str);
        staff = st;
    }

    public Tramwaj(int st, double v, String str)
    {
        super(v, str);
        staff = st;
    }

    public Tramwaj()
    {
        super();
        staff = 1;
    }

    @Override
    public String toString() {
        return "\n\t*Tramwaj skladajacy sie z " + staff
                + " wagonow to " + super.toString();
    }

    public int getStaff() {
        return staff;
    }

    public void setStaff(int staff) {
        this.staff = staff;
    }
}
