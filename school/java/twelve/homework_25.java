import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.*;
import javafx.stage.Stage;
import javafx.util.Duration;

public class homework_25 extends Application {
    @Override 
    public void start(Stage primaryStage) {    
        TextField Car_one = new TextField();
        TextField Car_two = new TextField();
        TextField Car_three = new TextField();
        TextField Car_four = new TextField();
        Car_one.setPrefColumnCount(2);
        Car_two.setPrefColumnCount(2);
        Car_three.setPrefColumnCount(2);
        Car_four.setPrefColumnCount(2);
    
        HBox hBox = new HBox(5);
        hBox.setAlignment(Pos.CENTER);
        hBox.getChildren().addAll(new Label("Car 1: "), Car_one,new Label("Car 2: "), Car_two, new Label("Car 3: "), Car_three,new Label("Car 4: "), Car_four);
    
        VBox vBox = new VBox(5);
        CarPane car1 = new CarPane();
        CarPane car2 = new CarPane();
        CarPane car3 = new CarPane();
        CarPane car4 = new CarPane();
    
        vBox.getChildren().addAll(car1, car2, car3, car4);
    
        BorderPane pane = new BorderPane();
        pane.setTop(hBox);
        pane.setCenter(vBox);

    
        Scene scene = new Scene(pane, 400, 200);
        primaryStage.setTitle("cck,20151681310210"); 
        primaryStage.setScene(scene); 
        primaryStage.show();  
    
        Car_one.setOnAction(e -> car1.setSpeed(Integer.parseInt(Car_one.getText())));
        Car_two.setOnAction(e -> car2.setSpeed(Integer.parseInt(Car_two.getText())));
        Car_three.setOnAction(e -> car3.setSpeed(Integer.parseInt(Car_three.getText())));
        Car_four.setOnAction(e -> car4.setSpeed(Integer.parseInt(Car_four.getText())));
    
        car1.widthProperty().addListener(e -> car1.setW(car1.getWidth()));
        car2.widthProperty().addListener(e -> car2.setW(car2.getWidth()));
        car3.widthProperty().addListener(e -> car3.setW(car3.getWidth()));
        car4.widthProperty().addListener(e -> car4.setW(car4.getWidth()));
    }
}

class CarPane extends Pane {
    private double w = 400;
    private double h = 40;
    private double baseX = 0;
    private double baseY = h;
    private Circle c1 = new Circle(baseX + 10 + 5, baseY - 10 + 5, 5);
    private Circle c2 = new Circle(baseX + 30 + 5, baseY - 10 + 5, 5);
  
    private Rectangle carBody = new Rectangle(baseX, baseY - 20, 50, 10);
    private Polygon carTop = new Polygon(baseX + 10, baseY - 20,baseX + 20, baseY - 30, baseX + 30, baseY - 30,baseX + 40, baseY - 20);  
    private int speed = 50;
  
    KeyFrame kf = new KeyFrame(Duration.millis(150 - speed), e -> move());
  
    Timeline animation = new Timeline(
        new KeyFrame(Duration.millis(150 - speed), e -> move()));
  
    public void setSpeed(int speed) {    
        animation.setRate(speed);
    } 
  
    public CarPane() {
        this.setStyle("-fx-border-color: black");
    
        carBody.setFill(Color.RED);
        carTop.setFill(Color.RED);
        this.getChildren().addAll(c1, c2, carBody, carTop);
    
        animation.setCycleCount(Timeline.INDEFINITE);
        animation.play(); 
    
        setOnMousePressed(e -> {
            animation.pause();
        });
        setOnMouseReleased(e -> {
            animation.play();
        });
    
        requestFocus();
        setOnKeyPressed(e -> {
        if (e.getCode() == KeyCode.UP) {
            animation.setRate(animation.getRate() + 1);
        } else if (e.getCode() == KeyCode.DOWN) {
            animation.setRate(animation.getRate() - 1);
      }
        });
    }
  
    public void move() {
        if (baseX > w) {
            baseX = -20;
        } else {
            baseX += 1;
        }
    
        setValues();
    }
  
    public void setValues() {
        c1.setCenterX(baseX + 10 + 5);
        c1.setCenterY(baseY - 10 + 5);
        c2.setCenterX(baseX + 30 + 5);
        c2.setCenterY(baseY - 10 + 5);
    
        carBody.setX(baseX);
        carBody.setY(baseY - 20);
    
        carTop.getPoints().clear();
        carTop.getPoints().addAll(baseX + 10, baseY - 20,baseX + 20, baseY - 30, baseX + 30, baseY - 30,baseX + 40, baseY - 20);    
    }
  
    public void setW(double w) {
        this.w = w;
        setValues();
    }
  
    public void setH(double h) {
        this.h = h;
        baseY = h;
        setValues();
    }
}
