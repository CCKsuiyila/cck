import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import javax.media.j3d.*;
import javax.vecmath.*;

public class E5 extends Applet{
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

        Shape3D shapelines=new Shape3D();
        //定义顶点坐标
        float vertexes[]={ .5f,0.5f,0.f, -0.5f,0.5f,0.0f,
                        0.5f,0.3f,0.0f, -0.5f,0.3f,0.0f,
                        -0.5f,-0.1f,0.0f, 0.5f,-0.1f,0.1f };
        //定义点颜色
        float pointcolors[]= {1.0f,0.f,0.f,  0.0f,1.f,0.f,
                            0.0f,0.f,1.0f,  1.0f,1.0f,0.f,
                            0.0f,1.0f,1.f,  1.f,0.f,1.0f };
        int vCount=6; 
        int indexCount=4;	
        int index[]={0,1,3,5};


        IndexedLineArray lines=new IndexedLineArray(vCount,LineArray.COORDINATES|LineArray.COLOR_3,indexCount);
        lines.setCoordinates(0,vertexes);
        lines.setCoordinateIndices(0,index);	
        lines.setColors(0,pointcolors);
        lines.setColorIndices(0,index);
        Appearance app=new Appearance();
        //定义线的属性
        LineAttributes linesattributes=new LineAttributes();

        //定义线的宽度
        linesattributes.setLineWidth(30.0f);
        linesattributes.setLineAntialiasingEnable(true);
        app.setLineAttributes(linesattributes);
        shapelines.setGeometry(lines);
        shapelines.setAppearance(app);

        transformgroup.addChild(shapelines);
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }

    public E5() {
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
        new MainFrame(new E5(),300,300); 
    }
}

