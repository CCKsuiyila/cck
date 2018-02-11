import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class E2 extends Applet{
    public BranchGroup createBranchGroup(){

        BranchGroup BranchGroupRoot=new BranchGroup();

        BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0);
        Color3f bgColor=new Color3f(0.5f,0.5f,0.5f);
        Background bg=new Background(bgColor);
        bg.setApplicationBounds(bounds);
        BranchGroupRoot.addChild(bg);

        TransformGroup transformgroup=new TransformGroup();
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        BranchGroupRoot.addChild(transformgroup);

        MouseRotate mouserotate=new MouseRotate();
        mouserotate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mouserotate);
        mouserotate.setSchedulingBounds(bounds);
        MouseZoom mousezoom=new MouseZoom();
        mousezoom.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousezoom);
        mousezoom.setSchedulingBounds(bounds);
        MouseTranslate mousetranslate=new MouseTranslate();
        mousetranslate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousetranslate);
        mousetranslate.setSchedulingBounds(bounds);

        Shape3D shapepoints=new Shape3D();
        //define the coordinate of the vertexes
        float vertexes[]={.5f,0.6f,0.0f, -0.5f,0.6f,0.0f,
                          0.5f,0.05f,0.0f,-0.5f,0.05f,0.f,
                          -0.5f,-0.7f,0.0f,0.5f,-0.7f,0.1f,};
        //define the color of the points
        float pointcolors[]={1.0f,0.f,0.0f,  0.0f,1.f,0.0f,
                             0.0f,0.f,1.0f,  1.0f,1.0f,0.f,
                             0.0f,1.0f,1.f,  1.f,0.f,1.0f};
        int vCount=6;
        PointArray points=new PointArray(vCount,PointArray.COORDINATES|PointArray.COLOR_3);
        points.setCoordinates(0,vertexes);
        points.setColors(0,pointcolors);
        Appearance app=new Appearance();

        //define the attribute of the points
        PointAttributes pointsattributes=new PointAttributes();
        //define the size of the points
        pointsattributes.setPointSize(70.0f);
        //spherical or spuare
        pointsattributes.setPointAntialiasingEnable(true);

        app.setPointAttributes(pointsattributes);

        shapepoints.setGeometry(points);
        shapepoints.setAppearance(app);
        transformgroup.addChild(shapepoints);

        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }
    public E2(){
        setLayout(new BorderLayout());

	Panel p = new Panel();
    	p.add(new Label("number:20151681310210, name:cck"));
        add(p, BorderLayout.NORTH);

        GraphicsConfiguration gc=SimpleUniverse.getPreferredConfiguration();
        Canvas3D c=new Canvas3D(gc);
        add("Center", c);
        BranchGroup BranchGroupScene=createBranchGroup();
        SimpleUniverse u=new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }
    public static void main(String[] args){
        new MainFrame(new E2(), 3300,300);
    }
}
