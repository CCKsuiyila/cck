import java.applet.Applet;
import java.awt.*;

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;

public class Name extends Applet {
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

        transformgroup.addChild(Striplines());
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }

    public Shape3D Striplines() {
        Shape3D Striplines0 = new Shape3D();
        float vertexes[] = {-.78f, 0.4f, 0.0f, -0.52f, 0.4f, 0.0f,
                -0.65f, .6f, 0.0f, -0.65f, -0.2f, 0.0f,
                -.65f, 0.37f, 0.0f, -0.8f, 0.0f, 0.0f,
                -.65f, 0.26f, 0.0f, -0.5f, 0.1f, 0.0f,//
                -.5f, 0.52f, 0.0f, -0.1f, 0.52f, 0.0f,
                -.52f, 0.25f, 0.0f, -0.05f, 0.25f, 0.0f,
                -0.1f, -0.2f, 0.0f, -0.3f, -0.15f, 0.0f,
                -.35f, 0.25f, 0.0f, -0.5f, 0.0f, 0.0f,
                -.18f, 0.25f, 0.0f, -0.43f, -0.2f, 0.0f,//
                0.05f, 0.53f, 0.0f, 0.3f, 0.53f, 0.0f,
                0.25f, 0.2f, 0.0f, 0.12f, 0.48f, 0.0f,
                0.07f, 0.2f, 0.0f, 0.32f, 0.2f, 0.0f,
                0.28f, -0.2f, 0.0f, 0.1f, -0.15f, 0.0f,
                0.04f, 0.0f, 0.0f, 0.27f, 0.06f, 0.0f,//
                0.35f, 0.43f, 0.0f, 0.7f, 0.49f, 0.0f,
                0.45f, 0.6f, 0.0f, 0.7f, 0.2f, 0.0f,
                0.75f, 0.35f, 0.0f, 0.68f, 0.38f, 0.0f,
                0.4f, 0.2f, 0.0f, 0.37f, 0.13f, 0.0f,
                0.75f, 0.13f, 0.0f, 0.50f, 0.13f, 0.0f,
                0.35f, -0.2f, 0.0f, 0.62f, 0.13f, 0.0f,
                0.62f, -0.2f, 0.0f, 0.75f, -0.2f, 0.0f,
                0.75f, -0.08f, 0.0f,//
        };
        float colors[] = {1.0f, 0.0f, 0.2f, 1.0f, 0.0f, 0.3f,
                1.0f, 0.0f, 0.4f, 1.0f, 0.0f, 0.5f,
                1.0f, 0.0f, 0.6f, 1.0f, 0.0f, 0.7f,
                1.0f, 0.0f, 0.8f, 1.0f, 0.0f, 0.9f,// 
                1.0f, 0.0f, 0.9f, 0.9f, 0.0f, 0.8f,
                0.8f, 0.0f, 0.8f, 0.7f, 0.0f, 0.8f,
                0.6f, 0.0f, 0.8f, 0.5f, 0.0f, 0.8f,
                0.4f, 0.0f, 0.8f, 0.3f, 0.0f, 0.8f,
                0.2f, 0.2f, 0.8f, 0.2f, 0.3f, 0.8f,// 
                0.2f, 0.4f, 0.8f, 0.2f, 0.5f, 0.8f,
                0.2f, 0.6f, 0.8f, 0.2f, 0.7f, 0.8f,
                0.2f, 0.8f, 0.8f, 0.2f, 0.9f, 0.8f,
                0.2f, 0.8f, 0.7f, 0.2f, 0.8f, 0.6f,
                0.2f, 0.8f, 0.5f, 0.2f, 0.8f, 0.4f,//
                0.2f, 0.8f, 0.3f, 0.2f, 0.8f, 0.2f,
                0.3f, 0.8f, 0.2f, 0.4f, 0.8f, 0.2f,
                0.5f, 0.8f, 0.2f, 0.6f, 0.8f, 0.2f,
                0.7f, 0.8f, 0.2f, 0.8f, 0.8f, 0.2f,
                0.8f, 0.7f, 0.2f, 0.8f, 0.6f, 0.2f,
                0.8f, 0.5f, 0.2f, 0.8f, 0.4f, 0.2f,
                0.8f, 0.3f, 0.2f, 0.8f, 0.2f, 0.2f,
                0.8f, 0.1f, 0.2f,
        };
        int[] substrips = new int[16];
        substrips[0] = 2;
        substrips[1] = 2;
        substrips[2] = 2;
        substrips[3] = 2;
        substrips[4] = 6;
        substrips[5] = 2;
        substrips[6] = 2;
        substrips[7] = 3;
        substrips[8] = 5;
        substrips[9] = 2;
        substrips[10] = 2;
        substrips[11] = 3;
        substrips[12] = 2;
        substrips[13] = 2;
        substrips[14] = 2;
        substrips[15] = 4;
        LineStripArray Striplines = new LineStripArray(43, LineArray.COORDINATES | LineArray.COLOR_3, substrips);
        Striplines.setCoordinates(0, vertexes);
        Striplines.setColors(0, colors);
        LineAttributes lineattributes = new LineAttributes();
        lineattributes.setLineWidth(9.0f);
        lineattributes.setLineAntialiasingEnable(true);
        lineattributes.setLinePattern(0);
        Appearance app = new Appearance();
        app.setLineAttributes(lineattributes);
        Striplines0.setGeometry(Striplines);
        Striplines0.setAppearance(app);
        return Striplines0;
    }

    public Name() {
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
        new MainFrame(new Name(), 800, 800);
    }
}
