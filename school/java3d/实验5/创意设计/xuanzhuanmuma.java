import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*; 
import javax.media.j3d.*; 
import javax.vecmath.*; 
import com.sun.j3d.utils.behaviors.mouse.*;
public class xuanzhuanmuma extends Applet {
    public static void main(String[] args) {
        new MainFrame(new xuanzhuanmuma(),500,500);
    }

    public xuanzhuanmuma() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
        p.add(new Label("name:cck,number:20151681310210 旋转木马"));
        add(p, BorderLayout.NORTH);
        GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
        Canvas3D c=new Canvas3D(gc);
        add("Center",c);
        BranchGroup BranchGroupScene=createBranchGroupSceneGraph();
        SimpleUniverse u=new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }

    public BranchGroup createBranchGroupSceneGraph() {

        BranchGroup BrachGroupRoot =new BranchGroup();

        BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0); 
        Color3f bgColor=new Color3f(1.0f,1.0f,1.0f); 
        Background bg=new Background(bgColor);
        bg.setApplicationBounds(bounds);
        BrachGroupRoot.addChild(bg);

        Color3f directionalColor=new Color3f(1.f,1.f,1.f); 
        Vector3f vec=new Vector3f(-1.f,-1.f,-1.0f); 
        DirectionalLight directionalLight=new DirectionalLight(directionalColor,vec);
        directionalLight.setInfluencingBounds(bounds); 
        BrachGroupRoot.addChild(directionalLight); 

        Appearance app1=new Appearance();
        Material material1=new Material();
        material1.setDiffuseColor(new Color3f(1.0f,.0f,0.0f));
        app1.setMaterial(material1); 
        Appearance app2=new Appearance();
        Material material2=new Material();
        material2.setDiffuseColor(new Color3f(.0f,1.0f,0.0f));
        app2.setMaterial(material2); 
        Appearance app3=new Appearance();
        Material material3=new Material();
        material3.setDiffuseColor(new Color3f(.0f,.0f,1.0f));
        app3.setMaterial(material3); 
        Appearance app4=new Appearance();
        Material material4=new Material();
        material4.setDiffuseColor(new Color3f(1.0f,1.0f,0.0f));
        app4.setMaterial(material4); 
        Appearance app5=new Appearance();
        Material material5=new Material();
        material5.setDiffuseColor(new Color3f(.0f,1.0f,1.0f));
        app5.setMaterial(material5); 
        Appearance app6=new Appearance();
        Material material6=new Material();
        material6.setDiffuseColor(new Color3f(1.0f,.0f,1.0f));
        app6.setMaterial(material6);

        Transform3D t=new Transform3D();
        t.setTranslation(new Vector3f(0.f,0.3f,0.f));
        TransformGroup transformgroup=new TransformGroup(t);
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        BrachGroupRoot.addChild(transformgroup);    
        MouseRotate mouserotate = new MouseRotate();
        mouserotate.setTransformGroup(transformgroup);
        BrachGroupRoot.addChild(mouserotate); 
        mouserotate.setSchedulingBounds(bounds); 
        MouseZoom mousezoom = new MouseZoom();
        mousezoom.setTransformGroup(transformgroup);
        BrachGroupRoot.addChild(mousezoom);
        mousezoom.setSchedulingBounds(bounds);
        MouseTranslate mousetranslate = new MouseTranslate();
        mousetranslate.setTransformGroup(transformgroup);
        BrachGroupRoot.addChild(mousetranslate);
        mousetranslate.setSchedulingBounds(bounds);

        t=new Transform3D();
        t.setTranslation(new Vector3f(0.0f,0.0f,0.0f));
        TransformGroup tg1=new TransformGroup(t);
        tg1.addChild(new Box(0.3f,0.15f,0.2f,app2));

        t=new Transform3D();
        t.setTranslation(new Vector3f(0.3f,0.0f,0.3f));
        TransformGroup tg2=new TransformGroup(t);
        tg2.addChild(new Sphere(0.2f,1,100,app1));
        t=new Transform3D();
        t.setTranslation(new Vector3f(-0.15f,0.1f,-0.3f));
        TransformGroup tg3=new TransformGroup(t);
        tg3.addChild(new Box(0.05f,0.05f,0.2f,app2));

        t=new Transform3D();
        t.setTranslation(new Vector3f(0.15f,0.1f,-0.3f));
        TransformGroup tg4=new TransformGroup(t);
        tg4.addChild(new Box(0.05f,0.05f,0.2f,app2));
        
        t=new Transform3D();
        t.setTranslation(new Vector3f(-0.15f,-0.1f,-0.3f));
        TransformGroup tg5=new TransformGroup(t);
        tg5.addChild(new Box(0.05f,0.05f,0.2f,app2));
        
        t=new Transform3D();
        t.setTranslation(new Vector3f(0.15f,-0.1f,-0.3f));
        TransformGroup tg6=new TransformGroup(t);
        tg6.addChild(new Box(0.05f,0.05f,0.2f,app2));
 
        t=new Transform3D();
        Vector3f vector3f=new Vector3f(1.f,1.f,1.f);
        vector3f.normalize();
        float theta=(float)Math.PI/2*3;
        Quat4f quat=new Quat4f();
        quat.x=(float)Math.sin(theta/2f)*vector3f.x;
        quat.y=(float)Math.sin(theta/2f)*vector3f.y;
        quat.x=(float)Math.sin(theta/2f)*vector3f.z;
        quat.w=(float)Math.cos(theta/2f);
        t.setRotation(quat);
        t.setTranslation(new Vector3f(-0.2f,-0.5f,0.65f));
        TransformGroup tg7=new TransformGroup(t);
        tg7.addChild(new Cylinder(0.05f,1.8f,app1));
        
        
        t=new Transform3D();
        vector3f=new Vector3f(1.f,1.f,1.f);
        vector3f.normalize();
        theta=(float)Math.PI;
        quat=new Quat4f();
        quat.x=(float)Math.sin(theta/2f)*vector3f.x;
        quat.y=(float)Math.sin(theta/2f)*vector3f.y;
        quat.x=(float)Math.sin(theta/2f)*vector3f.z;
        quat.w=(float)Math.cos(theta/2f);
        t.setRotation(quat);
        t.setTranslation(new Vector3f(-0.3f,0.f,0.0f));
        TransformGroup tg9=new TransformGroup(t);
        tg9.addChild(new Cylinder(0.05f,0.4f,app1));
        
        TransformGroup transformgroup0=new TransformGroup();
        transformgroup0.addChild(tg1);
        transformgroup0.addChild(tg2);
        transformgroup0.addChild(tg3);
        transformgroup0.addChild(tg4);
        transformgroup0.addChild(tg5);
        transformgroup0.addChild(tg6);
        transformgroup0.addChild(tg7);
        //transformgroup0.addChild(tg8);
        transformgroup0.addChild(tg9);
        //transformgroup0.addChild(tg10);
        
        SharedGroup sharedgroup=new SharedGroup();
        sharedgroup.addChild(transformgroup0);
        int i,j,k;
        float theta1,R=0.6f;
        theta1=2.0f*(float)Math.PI/5;

	    t=new Transform3D();
        t.setTranslation(new Vector3f(0.f,0.3f,0.f));
	    TransformGroup temp = new TransformGroup(t);
	    temp.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        temp.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        for(i=0;i<5;i++){
            Transform3D t1=new Transform3D();
            //t1.set(new AxisAngle4d(0.3,0.5,0.1,Math.PI*1.7*i));
            t1.setRotation(new AxisAngle4d(0.0,0.,0.3,Math.PI*1.7*i));
            t1.setScale(0.3f);
            t1.setTranslation(new Vector3f(R*(float)Math.sin(i*theta1),R*(float)Math.cos(i*theta1)-0.3f,0));

            TransformGroup sg1=new TransformGroup(t1);
	        sg1.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
            sg1.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
            sg1.addChild(new Link(sharedgroup));
	        temp.addChild(sg1);
        }
        
        
        Transform3D t2=new Transform3D();
        t2.setTranslation(new Vector3f(0.0f,-0.3f,0.35f));
        TransformGroup tg8=new TransformGroup(t2);
        tg8.addChild(new Box(0.8f,0.8f,0.015f,app2));
        temp.addChild(tg8);

	    t = new Transform3D();
        TransformGroup transformGroup22 = new TransformGroup(t);
        transformGroup22.addChild(temp);
        Alpha rotationAlpha22=new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
        Transform3D zAxis22 = new Transform3D();
        zAxis22.rotX(-Math.PI/2);
        zAxis22.setTranslation(new Vector3f(0.f, 0.f, 0.0f));
        RotationInterpolator rotator22=new RotationInterpolator(rotationAlpha22,temp, zAxis22, 0.0f, (float)Math.PI*2.0f);
        rotator22.setSchedulingBounds(bounds);
        transformGroup22.addChild(rotator22);
        transformgroup.addChild(transformGroup22);    
	

        BrachGroupRoot.compile();
        return BrachGroupRoot;
    }
}
