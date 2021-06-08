package sample;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import jdk.swing.interop.SwingInterOpUtils;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.*;

public class Controller {
    @FXML
    public Button Bdownload;
    @FXML
    public TextField TFmodelOfCar;
    @FXML
    public Hyperlink HLlink1;
    @FXML
    public Hyperlink HLlink2;
    @FXML
    public Hyperlink HLlink3;
    @FXML
    public Hyperlink HLlink4;
    @FXML
    public Hyperlink HLlink5;
    @FXML
    public Hyperlink HLlink6;
    @FXML
    public Hyperlink HLlink7;
    @FXML
    public Hyperlink HLlink8;
    @FXML
    public Hyperlink HLlink9;
    @FXML
    public Hyperlink HLlink10;
    @FXML
    public Label LPromptText;

    @FXML
    public void downloadLinks() throws Exception
    {
        URL otomoto = new URL(TFmodelOfCar.getText());
        BufferedReader in = new BufferedReader(new InputStreamReader(otomoto.openStream()));

        String inputLine;
        StringBuilder stringBuilder = new StringBuilder();
        while((inputLine = in.readLine()) != null)
        {
            stringBuilder.append(inputLine);
            stringBuilder.append(System.lineSeparator());
        }

        Set<String> setOfLinks = new TreeSet<>();
        String content = stringBuilder.toString();

        String tmp, tmp2;
        for(int i = 0; i < content.length(); i++) {
            i = content.indexOf("https://www.otomoto.pl/oferta/", i);
            if (i < 0)
                break;

            tmp = content.substring(i);
            setOfLinks.add(tmp.split(".html")[0] + ".html");
        }

        setOfLinks.forEach(System.out::println);

        Iterator<String> it = setOfLinks.iterator();

        HLlink1.setText(it.next());
        HLlink2.setText(it.next());
        HLlink3.setText(it.next());
        HLlink4.setText(it.next());
        HLlink5.setText(it.next());
        HLlink6.setText(it.next());
        HLlink7.setText(it.next());
        HLlink8.setText(it.next());
        HLlink9.setText(it.next());
        HLlink10.setText(it.next());

        in.close();
    }

    @FXML
    public void hidePromptText(){
        LPromptText.setVisible(false);
    }

}
