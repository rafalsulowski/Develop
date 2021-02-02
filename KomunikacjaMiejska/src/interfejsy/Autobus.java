package interfejsy;

public class Autobus extends Pojazd{
    private double FuelConsumption;

    public Autobus(double fc, double v, int n, String str)
    {
        super(v, n, str);
        FuelConsumption = fc;
    }

    public Autobus(double fc, double v, String str)
    {
        super(v, str);
        FuelConsumption = fc;
    }

    public Autobus()
    {
        super();
        FuelConsumption = 0.0;
    }

    @Override
    public String toString() {
        return "\n\t*Autobus o miesiecznym zuzyciu paliwa wynoszacym " +
                FuelConsumption + " to " + super.toString();
    }

    public double getFuelConsumption() {
        return FuelConsumption;
    }

    public void setFuelConsumption(double fuelConsumption) {
        FuelConsumption = fuelConsumption;
    }
}
