import java.applet.Applet;
import java.awt.*;

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;

public class E17 extends Applet {
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

        Shape3D RotationSurface = new SurfaceDisplay();
        transformgroup.addChild(RotationSurface);
        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }
    public E17() {
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

    public static void main(String argv[]) {
        new MainFrame(new E17(), 400, 400);
    }

    class SurfaceDisplay extends Shape3D {
        SurfaceDisplay(){
            this.setGeometry(createGeometry0());
            this.setAppearance(createAppearance0());
        } 
        float[][][] SurfacePointsxyz=new float[5][51][3];
        Geometry createGeometry0(){
            int i,j,k,c;
            int n0=50;
            float theta;

            //	
            float[] Xp0={.3f,.4f,.5f,.6f,.9f};
            float[] Yp0={-.4f,-.2f,0.f,.2f,.5f};
            //		
            theta=2.f*(float)Math.PI/n0;
            //
            for(i=0;i<5;i++){
                for(j=0;j<n0+1;j++){
                    SurfacePointsxyz[i][j][0]=Xp0[i]*(float)Math.cos(theta*j);

                    SurfacePointsxyz[i][j][1]=Yp0[i];
                    SurfacePointsxyz[i][j][2]=Xp0[i]*(float)Math.sin(theta*j);
                }
            }
            //
            QuadArray SurfaceQuadArray=new QuadArray(4*n0*4, GeometryArray.COORDINATES|GeometryArray.NORMALS);
            c=0;//
            for(i=0;i<4;i++){
                for(j=0;j<n0;j++){
                    Point3f A=new Point3f(SurfacePointsxyz[i][j][0],SurfacePointsxyz[i][j][1],SurfacePointsxyz[i][j][2]);
                    Point3f B=new Point3f(SurfacePointsxyz[i+1][j][0],SurfacePointsxyz[i+1][j][1],SurfacePointsxyz[i+1][j][2]);
                    Point3f C=new Point3f(SurfacePointsxyz[i+1][j+1][0],SurfacePointsxyz[i+1][j+1][1],SurfacePointsxyz[i+1][j+1][2]);
                    Point3f D=new Point3f(SurfacePointsxyz[i][j+1][0],SurfacePointsxyz[i][j+1][1],SurfacePointsxyz[i][j+1][2]);
                    //
                    Vector3f a = new Vector3f(A.x - B.x, A.y - B.y, A.z - B.z);
                    Vector3f b = new Vector3f(C.x - B.x, C.y - B.y, C.z - B.z);
                    Vector3f n= new Vector3f();
                    n.cross(b, a);
                    n.normalize();
                    //
                    SurfaceQuadArray.setCoordinate(c, A);
                    SurfaceQuadArray.setCoordinate(c+1, B);
                    SurfaceQuadArray.setCoordinate(c+2, C);
                    SurfaceQuadArray.setCoordinate(c+3, D);
                    //
                    SurfaceQuadArray.setNormal(c, n);
                    SurfaceQuadArray.setNormal(c+1, n);
                    SurfaceQuadArray.setNormal(c+2, n);
                    SurfaceQuadArray.setNormal(c+3, n);
                    c=c+4;
                }
            }
            return SurfaceQuadArray;
        }	
        Appearance createAppearance0() {
            //
            PolygonAttributes polygona=new PolygonAttributes();
            //
            polygona.setBackFaceNormalFlip(true);
            polygona.setCullFace(PolygonAttributes.CULL_NONE);
            //polygona.setPolygonMode(PolygonAttributes.POLYGON_LINE);
            //polygona.setPolygonMode(PolygonAttributes.POLYGON_POINT);
            Appearance appearance = new Appearance();
            appearance.setPolygonAttributes(polygona);
            Material material = new Material();
            Color3f white = new Color3f(1.0f, .0f, .0f);

            Color3f red   = new Color3f(.0f, .0f, 1.0f);
            material.setDiffuseColor(white);
            //material.setSpecularColor(red);
            //material.setShininess(20.0f);
            appearance.setMaterial(material);
            return appearance;
        }
    }		 
}



