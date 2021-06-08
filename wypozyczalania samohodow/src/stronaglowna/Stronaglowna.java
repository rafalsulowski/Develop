/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stronaglowna;

import java.io.IOException;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author konra
 */
public class Stronaglowna extends Application {
    
    Scene scene;
    Scene scene2;
    Scene scene3;
    Scene scene4;
    Stage primaryStage;
    
    @Override
    public void start(Stage primaryStage) throws IOException {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(this.getClass().getResource("stronaglowna.fxml"));
        
        FXMLLoader loader2 = new FXMLLoader();
        loader2.setLocation(this.getClass().getResource("logowanie.fxml"));
        
        FXMLLoader loader3 = new FXMLLoader();
        loader3.setLocation(this.getClass().getResource("rejestracja.fxml"));
        
        FXMLLoader loader4 = new FXMLLoader();
        loader4.setLocation(this.getClass().getResource("zalogowany.fxml"));
        
        Pane pane = loader.load();
        Pane pane2 = loader2.load();
        Pane pane3 = loader3.load();
        Pane pane4 = loader4.load();
        
        Controllerglowna controller = loader.getController();
        Controllerlogo controllerlogo = loader2.getController();
        Controllerrejestr controllerreje = loader3.getController();
        Controllerzalog controllerzalog = loader4.getController();
        
        scene = new Scene(pane);
        scene2 = new Scene(pane2);
        scene3 = new Scene(pane3);
        scene4 = new Scene(pane4);
        
        controller.scenecon1 = scene2;
        controller.scenecon2 = scene3;
        controller.stagecon = primaryStage;
        controllerreje.stagewroc = primaryStage;
        controllerreje.scenewroc = scene;
        controllerzalog.stagezalog = primaryStage;
        controllerzalog.scenelogout = scene;
        controllerlogo.stagelogo = primaryStage;
        controllerlogo.scenelogo = scene4;
        
        primaryStage.setScene(scene);
        
        primaryStage.setTitle("Wypożyczalnia samochodów");
        primaryStage.show();
    }
    
    
    
    public static void main(String[] args) {
        launch(args);
    }
    
}
