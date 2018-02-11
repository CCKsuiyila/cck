import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class E6 extends Applet{
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

        transformgroup.addChild(shapelines());
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }
    
    public Shape3D shapelines(){
        Shape3D Striplines0=new Shape3D();
        float vertexes[]={-0.8f,0.5f,0.0f,  0.8f,0.9f,0.0f,
                             -0.8f,0.2f,0.0f,  0.8f,0.7f,0.0f,
                             -0.8f,-0.2f,0.0f, 0.8f,-0.5f,0.0f,
                             -0.8f,-0.5f,0.0f, 0.8f,-.8f,0.0f,};
        float colors[]={1.0f,0.f,.0f,   0.0f,1.f,.0f,
                            0.0f,0.f,1.f,   1.0f,1.0f,0.f,
                            0.0f,1.0f,1.f,  1.f,0.f,1.0f,
                            0.0f,.0f,0.f,   0.3f,0.8f,0.0f,};
        int[] substrips=new int[2];
        substrips[0]=4;  substrips[1]=4;
        //int[] substrips=new int[1];
        //substrips[0]=8;  
        LineStripArray Striplines=new LineStripArray(8,LineArray.COORDINATES|LineArray.COLOR_3,substrips);
        Striplines.setCoordinates(0,vertexes);
        Striplines.setColors(0,colors);

        LineAttributes lineattributes=new LineAttributes();
        lineattributes.setLineWidth(9.0f);
        lineattributes.setLineAntialiasingEnable(true);
        lineattributes.setLinePattern(0);  	 
        Appearance app=new Appearance();  
        app.setLineAttributes(lineattributes);

        Striplines0.setGeometry(Striplines);
        Striplines0.setAppearance(app); 	
        return Striplines0;
    } 
    
    public E6() {
        setLayout(new BorderLayout());

	Panel p = new Panel();
    	p.add(new Label("number:20151681310210, name:cck"));
        add(p, BorderLayout.NORTH);

        GraphicsConfiguration gc=SimpleUniverse.getPreferredConfiguration();

        Canvas3D c=new Canvas3D(gc);
        add("Center",c);
        BranchGroup BranchGroupScene=createBranchGroup();
        SimpleUniverse u=new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }
    public static void main(String[] args) {
        new MainFrame(new E6(),300,300); 
    }
}






