
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class homework_11 extends Application{

    @Override
    public void start(Stage primaryStage){
        Pane pane = new Pane();
        Circle circle = new Circle(50,50,20);
        circle.setStroke(Color.BLACK);
        circle.setFill(Color.WHITE);
        pane.getChildren().add(circle);
        
        circle.setFocusTraversable(true);
        circle.setOnKeyPressed(e->{
            switch(e.getCode()){
                case DOWN: circle.setCenterY(circle.getCenterY()+2); break;
                case UP: circle.setCenterY(circle.getCenterY()-2); break;
                case LEFT: circle.setCenterX(circle.getCenterX()-2); break;
                case RIGHT: circle.setCenterX(circle.getCenterX()+2); break;
                default:
            }
        });


        Scene scene = new Scene(pane,300,200);
        primaryStage.setTitle("cck,20151681310210");
        primaryStage.setScene(scene);
        primaryStage.show();

        circle.requestFocus();
    }
    
}

