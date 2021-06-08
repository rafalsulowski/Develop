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

import static stronaglowna.User.login;


public class Controllerlogo {

    @FXML
    private Button btnLogIn;
    @FXML
    private PasswordField passwordL;
    @FXML
    private TextField emailL;
    @FXML
    private Label errorL;

    Stage stagelogo;
    Scene scenelogo;
    
    public void btnLogIn_Logowanie(ActionEvent event)
    {
        errorL.setVisible(false);
        String password, email;

        email = emailL.getText();
        password = passwordL.getText();

        UserDatabase database = new UserDatabase("users.txt");
        String errorText = login(email, password);

        if (!errorText.equals("correct")) {
            errorL.setVisible(true);
        }
        else {
                loggedin();
        }
    }
    
    public void loggedin(){
        stagelogo.setScene(scenelogo);      
    }
}
