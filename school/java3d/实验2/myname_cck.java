import java.applet.Applet;
import java.awt.*;


import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;

public class myname_cck extends Applet {
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

        transformgroup.addChild(Shapelines());
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }

    public Shape3D Shapelines() {
        Shape3D shapelines0= new Shape3D();
        float vertexes[] = 
        	   {-0.50f,0.80f,0.00f,-0.60f,+0.30f,0.00f,
        	    +0.40f,0.90f,0.00f,+0.60f,+0.40f,0.00f,
        	    -0.05f,1.00f,0.00f,+0.00f,+0.40f,0.00f,
        	    -0.60f,0.30f,0.00f,+0.555f,+0.50f,0.00f,//
        	    -0.10f,0.25f,0.00f,-0.70f,-0.10f,0.00f,
        	    -0.35f,0.10f,0.00f,-0.35f,-1.00f,0.00f,
        	    +0.05f,0.20f,0.00f,+0.15f,+0.10f,0.00f,
        	    -0.10f,0.00f,0.00f,+0.45f,+0.10f,0.00f,
        	    -0.05f,-0.25f,0.00f,+0.40f,-0.15f,0.00f,
        	    -0.05f,-0.50f,0.00f,+0.40f,-0.40f,0.00f,
        	    -0.20f,-0.75f,0.00f,+0.60f,-0.70f,0.00f,
        	    +0.17f,+0.05f,0.00f,+0.17f,-0.725f,0.00f,//
                +1.50f,0.90f,0.00f,+1.70f,+0.40f,0.00f,
                +1.52f,0.90f,0.00f,+2.40f,+1.00f,0.00f,
                +2.40f,+1.00f,0.00f,+2.20f,0.40f,0.00f,
                +1.60f,+0.70f,0.00f,+2.00f,+0.70f,0.00f,
                +1.70f,+0.40f,0.00f,2.20f,0.40f,0.00f,//
                +1.30f,0.20f,0.00f,+2.60f,0.20f,0.00f,
                +1.60f,0.20f,0.00f,+1.45f,-1.00f,0.00f,
                +1.80f,+0.00f,0.00f,+2.20f,+0.00f,0.00f,
                +1.85f,-0.20f,0.00f,+2.15f,-0.20f,0.00f,
                +1.85f,-0.20f,0.00f,+1.83f,-0.80f,0.00f,
                +1.83f,-0.80f,0.00f,+2.00f,-0.60f,0.00f,
                +2.10f,-0.50f,0.00f,+2.30f,-0.30f,0.00f,
                +1.84f,-0.40f,0.00f,2.60f,-0.70f,0.00f,


        };
        float colors[] = {
        		1.0f, 0.0f, 0.2f, 1.0f, 0.0f, 0.3f,
                1.0f, 0.0f, 0.4f, 1.0f, 0.0f, 0.5f,
                1.0f, 0.0f, 0.6f, 1.0f, 0.0f, 0.7f,
                1.0f, 0.0f, 0.8f, 1.0f, 0.0f, 0.9f,
                1.0f, 0.0f, 0.6f, 1.0f, 0.0f, 0.7f,
                1.0f, 0.0f, 0.8f, 1.0f, 0.0f, 0.9f,
                1.0f, 0.0f, 0.9f, 0.9f, 0.0f, 0.8f,
                0.8f, 0.0f, 0.8f, 0.7f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.6F, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,

                
        };
        LineArray lines = new LineArray(50, LineArray.COORDINATES | LineArray.COLOR_3);
        lines.setCoordinates(0, vertexes);
        lines.setColors(0, colors);
        LineAttributes lineattributes = new LineAttributes();
        lineattributes.setLineWidth(9.0f);
        lineattributes.setLineAntialiasingEnable(true);
        lineattributes.setLinePattern(0);
        Appearance app = new Appearance();
        app.setLineAttributes(lineattributes);
        shapelines0.setGeometry(lines);
        shapelines0.setAppearance(app);
        return shapelines0;
    }

    public myname_cck() {
        setLayout(new BorderLayout());
        Panel p = new Panel();
    	p.add(new Label("number:20151681310210, name:cck"));
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
        new MainFrame(new myname_cck(), 800,900);
    }
}
