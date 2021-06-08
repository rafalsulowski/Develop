package stronaglowna;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;

public class Car {
    String name;
    String price;
    String segment;
    String power;
    String fuel_consumption;
    String fuel_type;
    String gearbox_type;
    String photo;
    String avaiable;
    String rentedTo;

    public Car(String line)
    {
        String [] data = line.split(" ");
        this.name = data[0];
        this.price = data[1];
        this.segment = data[2];
        this.power = data[3];
        this.fuel_consumption = data[4];
        this.fuel_type = data[5];
        this.gearbox_type = data[6];
        this.photo = data[7];
        this.avaiable = data[8];
        this.rentedTo = data[9];
    }
}

class CarDatabase {
    Car [] cars = new Car[100];
    int counter;
    String fileName;
    public CarDatabase(String filename)
    {
        try {
            int counter = 0;
            File myObj = new File(filename);
            this.fileName = filename;
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();
                this.cars[counter] = new Car(line);
                counter++;
                this.counter = counter;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
    public String rentCar(int index, String userEmail)
    {
        return changeAvailability(index, "NotAvailable", userEmail);
    }
    public void returnCar(int index)
    {
        changeAvailability(index, "Available", "None");
    }
    private String changeAvailability(int index, String changeTo, String renter)
    {
        this.cars[index].avaiable = changeTo;
        this.cars[index].rentedTo = renter;
        return updateDataBase();
    }
    private String updateDataBase()
    {
        File myObj = new File(this.fileName);
        myObj.delete();
        for(int i = 0; i < this.counter; i++){
            try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter(this.fileName, true));
                    StringBuilder userCar = new StringBuilder();

                    writer.append(this.cars[i].name + ' ' + this.cars[i].price + ' ' + this.cars[i].segment + ' ' + this.cars[i].power + ' ' + this.cars[i].fuel_consumption + ' ' + this.cars[i].fuel_type + ' ' + this.cars[i].gearbox_type + ' ' + this.cars[i].photo + ' ' + this.cars[i].avaiable + ' ' + this.cars[i].rentedTo + '\n');
                    userCar.append(this.cars[i].name + "\nCena za dobę: " + this.cars[i].price + " [zł]\nSegment: " + this.cars[i].segment + "\nMoc: " + this.cars[i].power +"\nZużycie paliwa: " + this.cars[i].fuel_consumption + "\nTyp paliwa: " + this.cars[i].fuel_type + "\nSkrzynia biegów: " + this.cars[i].gearbox_type + '\n');

                    System.out.println("Successfully wrote to the file.");
                    writer.close();
                return userCar.toString();

            } catch (IOException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();

                }
            }
        return  "";
    }
}