package stronaglowna;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;


public class Controllerrejestr {
    @FXML
    private Button btnRegister;
    @FXML
    private Button homePage;
    @FXML
    private TextField nameL;
    @FXML
    private TextField surnameL;
    @FXML
    private TextField emailL;
    @FXML
    private PasswordField passwordL;
    @FXML
    private PasswordField repPasswordL;
    @FXML
    private TextField adresL;
    @FXML
    private TextField telL;
    @FXML
    private  Label errorL;
    
    Stage stagewroc;
    Scene scenewroc;


    public void Register(ActionEvent event) {
        errorL.setVisible(false);
        errorL.setText("Błąd!");

        String name, surname, email, password, adres, tel;
        boolean correctInput = true;

        name = nameL.getText();
        surname = surnameL.getText();
        email = emailL.getText();
        password = passwordL.getText();
        adres = adresL.getText();
        tel = telL.getText();

        if(!password.equals(repPasswordL.getText()))
        {
            errorL.setText("Hasła nie są identyczne");
            errorL.setVisible(true);
        }
        else {
            UserDatabase database = new UserDatabase("users.txt");
            String errorText = database.addUserToDatabase(email, password, name, surname, adres, tel);

            if (!errorText.equals("correct")) {
                errorL.setText(errorText);
                errorL.setVisible(true);
            }
            else {
                backtoglowna();
            }
        }
        email = "";
    }
    
    public void backtoglowna(){
          stagewroc.setScene(scenewroc);     
    }
}
