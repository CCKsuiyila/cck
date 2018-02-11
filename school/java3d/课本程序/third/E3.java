import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class E3 extends Applet{
    public BranchGroup createBranchGroup(){

        BranchGroup BranchGroupRoot=new BranchGroup();

        BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0);
        Color3f bgColor=new Color3f(1.0f,1.0f,1.0f);
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
        //define the coordinates of the vertexes
        float vertexes[]={.5f,0.6f,0.0f,  -0.5f,0.6f,0.0f,
                          0.5f,0.05f,0.0f, -0.5f,0.05f,0.f,

                         -0.5f,-0.7f,0.0f,  0.5f,-0.7f,0.1f,};
        //定义点颜色
        float pointcolors[]={1.0f,0.f,0.0f,  0.0f,1.f,0.f,
                               0.0f,0.f,1.0f,  1.0f,1.0f,0.f,
                              0.0f,1.0f,1.f,  1.f,0.f,1.0f  };

        int vCount=6; 
	    int indexCount=3;	
	    int index[]={0,3,5};

	    IndexedPointArray points=new IndexedPointArray(vCount,PointArray.COORDINATES|PointArray.COLOR_3,indexCount);
	    points.setCoordinates(0,vertexes);
	    points.setCoordinateIndices(0,index);	
	    points.setColors(0,pointcolors);
	    points.setColorIndices(0,index);

	    Appearance app=new Appearance();
	    PointAttributes pointsattributes=new PointAttributes();
	    pointsattributes.setPointSize(70.0f);
	    pointsattributes.setPointAntialiasingEnable(true);
	    app.setPointAttributes(pointsattributes);
	    shapepoints.setGeometry(points);
	    shapepoints.setAppearance(app);
	    transformgroup.addChild(shapepoints);
	    BranchGroupRoot.compile();
	    return BranchGroupRoot;

    }

    public E3() {
        setLayout(new BorderLayout());
        GraphicsConfiguration gc=SimpleUniverse.getPreferredConfiguration();

        Canvas3D c=new Canvas3D(gc);
        add("Center",c);
        BranchGroup BranchGroupScene=createBranchGroup();
        SimpleUniverse u=new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }
    public static void main(String[] args) {
        new MainFrame(new E3(),300,300); 
    }
}
