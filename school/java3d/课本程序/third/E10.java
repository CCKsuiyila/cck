import java.applet.Applet;
import java.awt.*;

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;

public class E10 extends Applet {
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

        transformgroup.addChild(new  ShapeTriangleFanArray());
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }

    
    public E10() {
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
        new MainFrame(new E10(), 300, 300);
    }
    class ShapeTriangleFanArray extends Shape3D {
        public ShapeTriangleFanArray() {
            int vertexesCount=12;
            int stripCount[]=new int[1];
            float vertexes[]={ .0f,0.9f,0.0f,   -1.f,-0.8f,0.f,
                            -0.8f,-0.6f,-0.2f, -0.6f,-0.9f,0.2f,
                            -0.4f,-0.8f,-0.2f,  0.f,-0.8f,0.2f,
                            0.2f,-0.5f,0.0f,   0.4f,-0.6f,-0.5f,
                            0.6f,-0.8f,-0.3f,  0.8f,-0.9f,-0.2f,
                            0.9f,-0.7f,-0.2f,  1.1f,-0.8f,-0.3f};
            stripCount[0]=12;
            TriangleFanArray triangleFanarray=new TriangleFanArray(vertexesCount,
            TriangleFanArray.COORDINATES|TriangleFanArray.NORMALS,stripCount);
            triangleFanarray.setCoordinates(0,vertexes);
            PolygonAttributes polygonattributes=new PolygonAttributes();
            polygonattributes.setCullFace(PolygonAttributes.CULL_NONE);
            Appearance app=new Appearance();
            //可用下列三条语句单独定义不可分割体的颜色属性
            ColoringAttributes coloringAttributes =new ColoringAttributes();
            coloringAttributes.setColor(1.f, 0.f, 0.f);
            app.setColoringAttributes(coloringAttributes);
            //颜色定义结束
            app.setPolygonAttributes(polygonattributes);
            this.setGeometry(triangleFanarray);
            this.setAppearance(app);
        }
    } 
}



    

