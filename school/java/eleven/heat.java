
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class heat extends Application{

    public Label lb1;
    public TextField heat_inform;
    @Override
    public void start(Stage primaryStage){
        HBox pane_one = new HBox();

        Image image = new Image("image/food2.jpg");
        ImageView imageview = new ImageView(image);
        lb1 = new Label("",imageview);
        pane_one.getChildren().add(lb1);

        VBox pane_two = new VBox();
        heat_inform = new TextField("微波炉已经停止加热");
        pane_two.getChildren().add(heat_inform);
        
        GridPane pane_three = new GridPane();
        pane_three.add(new Button("   1    "),0,0);
        pane_three.add(new Button("   2    "),1,0);
        pane_three.add(new Button("   3    "),2,0);
        pane_three.add(new Button("   4    "),0,1);
        pane_three.add(new Button("   5    "),1,1);
        pane_three.add(new Button("   6    "),2,1);
        pane_three.add(new Button("   7    "),0,2);
        pane_three.add(new Button("   8    "),1,2);
        pane_three.add(new Button("   9    "),2,2);
        pane_three.add(new Button("   0    "),0,3);
        Button button_start = new Button("  start");
        startHandlerClass handler1 = new startHandlerClass();
        button_start.setOnAction(handler1);
        
        Button button_stop  = new Button("  stop");
        
        stopHandlerClass handler2 = new stopHandlerClass();
        button_stop.setOnAction(handler2);  
        
        pane_three.add(button_start,1,3);
        pane_three.add(button_stop,2,3);
        pane_two.getChildren().add(pane_three);
        
        pane_one.getChildren().add(pane_two);
        
        
       
        
        Scene scene = new Scene(pane_one);
        primaryStage.setTitle("cck,20151681310210");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    class startHandlerClass implements EventHandler<ActionEvent>{
        @Override
        public void handle(ActionEvent e){
            heat_inform.setText("正在加热");
            lb1.setGraphic(new ImageView(new Image("image/food1.jpg")));
        }

    }
    class stopHandlerClass implements EventHandler<ActionEvent>{
        @Override
        public void handle(ActionEvent e){
            heat_inform.setText("微波炉已经停止加热");
            lb1.setGraphic(new ImageView(new Image("image/food2.jpg")));
        }

    }

}

