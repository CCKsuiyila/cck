import java.util.Scanner;
import javafx.animation.PathTransition;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import javafx.util.Duration;

public class homework_27 extends Application{

	
    public void start(Stage primaryStage){
       Pane pane = new Pane();

       Line line = new Line(30,50,315,50);

       Text text = new Text(20,20,"Programming is fun");

       pane.getChildren().add(text);

       PathTransition pt = new PathTransition();
       pt.setDuration(new Duration(4000));
       pt.setPath(line);
       pt.setNode(text);
       pt.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
       pt.setCycleCount(Timeline.INDEFINITE);
       pt.setAutoReverse(false);
       pt.play();

       text.setOnMousePressed(e->pt.pause());
       text.setOnMouseReleased(e->pt.play());

       Scene scene = new Scene(pane,250,200);
       primaryStage.setTitle("cck,20151681310210");
       primaryStage.setScene(scene);
       primaryStage.show();

        
    }
}

    
