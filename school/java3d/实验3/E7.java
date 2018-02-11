import java.applet.Applet;
import java.awt.*;

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;

public class E7 extends Applet {
    public BranchGroup createBranchGroup() {

        BranchGroup BranchGroupRoot = new BranchGroup();

        BoundingSphere bounds = new BoundingSphere(new Point3d(0.0, 0.0, 0.0), 100.0);
        Color3f bgColor = new Color3f(1.0f, 1.0f, 1.0f);
        Background bg = new Background(bgColor);
        bg.setApplicationBounds(bounds);
        BranchGroupRoot.addChild(bg);

        Color3f directionalColor = new Color3f(1.f, 0.f, 0.f);
        Vector3f vec = new Vector3f(0.f, 0.f, -1.0f);
        DirectionalLight directionalLight = new DirectionalLight(directionalColor, vec);
        directionalLight.setInfluencingBounds(bounds);
        BranchGroupRoot.addChild(directionalLight);

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
        MouseTranslate mousetranslate = new MouseTranslate();
        mousetranslate.setTransformGroup(transformgroup);
        BranchGroupRoot.addChild(mousetranslate);
        mousetranslate.setSchedulingBounds(bounds);

        transformgroup.addChild(new TriangleArrays());
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }

    public E7() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
    	p.add(new Label("name:cck, number:20151681310210"));
    	add(p, BorderLayout.NORTH);
        GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
        Canvas3D c = new Canvas3D(gc);
        add("Center", c);
        BranchGroup BranchGroupScene = createBranchGroup();
        SimpleUniverse u = new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }

    public static void main(String[] args) {
        new MainFrame(new E7(), 300, 300);
    }

    class TriangleArrays extends Shape3D{
        public TriangleArrays(){

            int vCount=12;
    
            float vertexes[]={ -0.6f,0.9f,0.f,  -0.6f,-0.9f,0.2f,
                   -0.4f,0.9f,-0.2f, -0.2f,-0.9f,0.2f,
                    0.0f,0.9f,-0.2f,  0.0f,-0.9f,0.2f,
                    0.2f,0.7f,0.0f,   0.2f,-0.9f,0.3f,
                    0.5f,0.8f,-0.3f,  0.6f,-.9f,0.0f,
                    0.8f,0.9f,0.2f,   0.8f,-0.8f,0.3f  };
            float colors[]={    0.0f,0.5f,1.f,    0.0f,0.5f,1.f,
                               0.0f,0.8f,.0f,    1.0f,0.0f,0.3f,
                               0.0f,1.0f,0.5f,   0.9f,1.0f,0.0f,
                               0.5f,0.0f,1.0f,   0.0f,0.5f,1.0f,
                               1.0f,0.5f,0.0f,   1.0f,0.0f,0.5f,
                               1.0f,0.8f,0.0f,   1.0f,0.5f,0.0f };
            TriangleArray trianglearray= new TriangleArray(vCount,TriangleArray.COORDINATES|TriangleArray.COLOR_3);  		
            trianglearray.setCoordinates(0,vertexes);
            trianglearray.setColors(0,colors);

            PolygonAttributes polygonattributes=new PolygonAttributes();
            polygonattributes.setCullFace(PolygonAttributes.CULL_NONE);
            //polygonattributes.setCullFace(PolygonAttributes.CULL_FRONT);
            //polygonattributes.setCullFace(PolygonAttributes.CULL_BACK);
            Appearance app=new Appearance();
            app.setPolygonAttributes(polygonattributes);

            this.setGeometry(trianglearray);
            this.setAppearance(app);
        } 
    } 
}


