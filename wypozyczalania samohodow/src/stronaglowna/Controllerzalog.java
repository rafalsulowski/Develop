/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stronaglowna;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 *
 * @author konra
 */
public class Controllerzalog {
    Stage stagezalog;
    Scene scenelogout;

    @FXML
    public ImageView image;
    @FXML
    public ImageView image1;
    @FXML
    public ImageView image11;
    @FXML
    public ImageView image111;
    @FXML
    public ImageView image1111;

    @FXML
    public Label parametryauta;
    @FXML
    public Label parametryauta1;
    @FXML
    public Label parametryauta11;
    @FXML
    public Label parametryauta111;
    @FXML
    public Label parametryauta1111;

    @FXML
    void initialize() throws FileNotFoundException {
        CarDatabase carDatabase = new CarDatabase("cars.txt");

        InputStream stream = new FileInputStream("C:\\Users\\rmsul\\Desktop\\IdeaProjects\\scalony\\src\\stronaglowna\\zdj\\zd1.png");


        Image tmp = new Image(stream);
        image.setImage(tmp);

        Image tmp1 = new Image(stream);
        image1.setImage(tmp);

        Image tmp11 = new Image(stream);
        image11.setImage(tmp);

        Image tmp111 = new Image(stream);
        image111.setImage(tmp);

        Image tmp1111 = new Image(stream);
        image1111.setImage(tmp);


        parametryauta.setText(carDatabase.rentCar(0, "ra@wp.pl"));
        parametryauta1.setText(carDatabase.rentCar(1, "ra@wp.pl"));
        parametryauta11.setText(carDatabase.rentCar(2, "ra@wp.pl"));
        parametryauta111.setText(carDatabase.rentCar(3, "ra@wp.pl"));
        parametryauta1111.setText(carDatabase.rentCar(4, "ra@wp.pl"));
    }
    
    @FXML
    public void onActionlogoutBu(ActionEvent e) {
        logout();
        
    }
    

    public void logout(){
        stagezalog.setScene(scenelogout);      
    }
}
