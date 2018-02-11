import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class E1 extends Applet{
    public BranchGroup createBranchGroup(){

        BranchGroup BranchGroupRoot = new BranchGroup();

        BoundingSphere bounds = new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0);

        Color3f bgColor = new Color3f(1.0f,1.0f,1.0f);
        Background bg = new Background(bgColor);
        bg.setApplicationBounds(bounds);BranchGroupRoot.addChild(bg);

        Color3f directionalColor = new Color3f(1.f,1.f,1.f);
        Vector3f vec = new Vector3f(-1.f,-1.f,-1.0f);
        DirectionalLight directionalLight = new DirectionalLight(directionalColor,vec);
        directionalLight.setInfluencingBounds(bounds);
        BranchGroupRoot.addChild(directionalLight);

        Appearance app1 = new Appearance();
        Material materiall = new Material();
        materiall.setDiffuseColor(new Color3f(1.0f,.0f,0.0f));
        app1.setMaterial(materiall);
        Appearance app2 = new Appearance();
        Material material2 = new Material();
        material2.setDiffuseColor(new Color3f(.0f,1.0f,0.0f));
        app2.setMaterial(material2);

        TransformGroup transformgroup = new TransformGroup();

        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);

        BranchGroupRoot.addChild(transformgroup);  

        MouseRotate mouserotate = new MouseRotate();
        mouserotate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mouserotate);
        mouserotate.setSchedulingBounds(bounds);

        MouseZoom mousezoom = new MouseZoom();
        mousezoom.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousezoom);
        mousezoom.setSchedulingBounds(bounds);

        TransformGroup tg1 = new TransformGroup();
        tg1.addChild(new Sphere(0.4f,app1));
        Transform3D t = new Transform3D();
        t.setTranslation(new Vector3f(0.f,-0.425f,0.f));
        TransformGroup tg2 = new TransformGroup(t);
        tg2.addChild(new Box(0.5f,0.05f,0.5f,app2));

        transformgroup.addChild(tg1);
        transformgroup.addChild(tg2);

        BranchGroupRoot.compile();

        return BranchGroupRoot;
    }
    
    public E1(){
        setLayout(new BorderLayout());
                
        GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
        Canvas3D c = new Canvas3D(gc);

        add("Center",c);

        BranchGroup BranchGroupScene = createBranchGroup();
        SimpleUniverse u = new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();

        u.addBranchGraph(BranchGroupScene);
    }

    public static void main(String[] args){
        new MainFrame(new E1(),300,300);
    }
}
