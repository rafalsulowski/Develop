package stronaglowna;
import java.io.FileWriter;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.File;
import java.io.FileNotFoundException;

public class User {
    String email;
    String password;
    String name;
    String surname;
    String address;
    String phone;

    public User(String email, String password, String name, String surname, String address, String phone)
    {
        this.email = email;
        this.password = password;
        this.name = name;
        this.surname = surname;
        this.address = address;
        this.phone = phone;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        UserDatabase database = new UserDatabase("users.txt");
        System.out.println("email: ");
        String email = myObj.nextLine();
        System.out.println("password: ");
        String password = myObj.nextLine();
        System.out.println("name: ");
        String name = myObj.nextLine();
        System.out.println("surname: ");
        String surname = myObj.nextLine();
        System.out.println("address: ");
        String address = myObj.nextLine();
        System.out.println("phone: ");
        String phone = myObj.nextLine();
        myObj.close();
        database.addUserToDatabase(email, password, name, surname, address, phone);
        //System.out.println(database.users[0].email + " " + database.users[0].password + " " +database.users[0].name + " " +database.users[0].surname + " " + database.users[0].address + " " + database.users[0].phone);
    }

    public static String login(String email, String haslo){
        UserDatabase database = new UserDatabase("users.txt");
        int index = database.IsEmailAlreadyRegistered(email);
        if (index >= 0)
        {
            if (database.users[index].password.equals(haslo)) {
                System.out.println("logowanie");
                return "correct";
            }
            else {
                System.out.println("Nie udało się zalogować");
                return "incorrect";
            }
        }
        else
        {
            System.out.println("Nie udało się zalogować");
            return "incorrect";
        }
    }

}

class UserDatabase {
    User [] users = new User[100];
    int counter;
    public UserDatabase(String filename)
    {
        try {
            int counter = 0;
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();
                this.users[counter] = getUserFromString(line);
                counter++;
                this.counter = counter;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
    User getUserFromString(String line)
    {
        String[] data = line.split(" ");
        User u = new User(data[0], data[1], data[2], data[3], data[4], data[5]);
        return u;
    }
    String addUserToDatabase(String email, String password, String name, String surname, String address, String phone)
    {
        String errorText = validateInput(email, password, name, surname, address, phone);
        if(errorText.equals("correct")) {
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("users.txt", true));
                writer.append(email + ' ' + password + ' ' + name + ' ' + surname + ' ' + address + ' ' + phone + '\n');
                writer.close();
                System.out.println("Successfully wrote to the file.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        }

        return errorText;
    }
    String validateInput(String email, String password, String name, String surname, String address, String phone)
    {
        if(checkName(name) == false) {
            System.out.println("zle imie");
            return "zle imie";
        }
        if(checkName(surname) == false) {
            System.out.println("zle nazwisko");
            return "zle nazwisko";
        }
        if(checkIfEmail(email) == false) {
            System.out.println("zly email");
            return "zly email";
        }
        if(checkPassword(password) == false)
        {
            System.out.println("zle haslo");
            return "zle haslo";
        }
        if(IsEmailAlreadyRegistered(email) != -1)
        {
            System.out.println("juz istnieje konto z tym emailem");
            return "juz istnieje konto z tym emailem";
        }
        if(checkPhone(phone) == false) {
            System.out.println("zly numer");
            return "zly numer";
        }

        return "correct";
    }
    public boolean checkIfEmail(String email){
        Pattern pattern = Pattern.compile("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}");
        Matcher mat = pattern.matcher(email);
        if(mat.matches())
            return true;
        else
            return false;
    }
    public boolean checkPassword(String password)
    {
        String regex = "^(?=.*[0-9])" + "(?=.*[a-z])(?=.*[A-Z])" + "(?=.*[@#$%^&+=])" + "(?=\\S+$).{8,20}$";
        Pattern p = Pattern.compile(regex);
        if (password == null) {
            return false;
        }
        Matcher m = p.matcher(password);
        return m.matches();
    }
    public boolean checkName(String name){
        if(name.contains(" "))
            return false;
        else
            return true;
    }
    boolean checkPhone(String phone){
        Pattern pattern = Pattern.compile("\\d{9}");
        Matcher mat = pattern.matcher(phone);
        if(mat.matches())
            return true;
        else
            return false;
    }
    public int IsEmailAlreadyRegistered(String email)
    {
        for (int i = 0; i < this.counter; i++) {
            if(this.users[i].email.equals(email))
                return i;
        }
        return -1;
    }
}