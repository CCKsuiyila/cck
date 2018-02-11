import java.applet.*;
import java.awt.*;
import javax.vecmath.*;
import javax.media.j3d.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.behaviors.mouse.*;
public class E20 extends Applet{
	public static void main(String[] args){
		new MainFrame(new E20(),640,580);
	}
	public void init(){
	    Panel p = new Panel();
    	p.add(new Label("name:cck, number:20151681310210"));
    	add(p, BorderLayout.NORTH);	
        GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
		
		Canvas3D cv = new Canvas3D(gc);
		setLayout(new BorderLayout());
		add(cv,BorderLayout.CENTER);
		BranchGroup bg = createSceneGraph();
		bg.compile();
		SimpleUniverse su = new SimpleUniverse(cv);
		su.getViewingPlatform().setNominalViewingTransform();
		su.addBranchGraph(bg);
	}
	private BranchGroup createSceneGraph(){
		BranchGroup root = new BranchGroup();
		TransformGroup spin=new TransformGroup();
		spin.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
		spin.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
		root.addChild(spin);
		Appearance ap=new Appearance();
		//
		PolygonAttributes polygonal=new PolygonAttributes();
		polygonal.setBackFaceNormalFlip(true);
		ap.setPolygonAttributes(polygonal);
		ap.setMaterial(new Material());
		Shape3D shape =new createGeometry();
		shape.setAppearance(ap);
		Transform3D tr = new Transform3D();
		tr.setScale(0.5);
		TransformGroup transformgroup = new TransformGroup(tr);
		spin.addChild(transformgroup);
		transformgroup.addChild(shape);
		BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0);
		MouseRotate mouserotate = new MouseRotate();
		mouserotate.setTransformGroup(spin);
		root.addChild(mouserotate);
		mouserotate.setSchedulingBounds(bounds);
		MouseZoom mousezoom = new MouseZoom();
		mousezoom.setTransformGroup(spin);
		root.addChild(mousezoom);
		mousezoom.setSchedulingBounds(bounds);
		MouseTranslate mousetranslate = new MouseTranslate();
		mousetranslate.setTransformGroup(spin);
		root.addChild(mousetranslate);
		mousetranslate.setSchedulingBounds(bounds);
		Background background = new Background(1.0f,1.0f,1.0f);
		background.setApplicationBounds(bounds);
		root.addChild(background);
		AmbientLight light = new AmbientLight(true,new Color3f(Color.red));
		light.setInfluencingBounds(bounds);
		root.addChild(light);
		PointLight ptlight = new PointLight(new Color3f(Color.red),new Point3f(3f,3f,3f), new Point3f(1f,0f,0f));
		ptlight.setInfluencingBounds(bounds);
		root.addChild(ptlight);
		return root;
	}
}

class createGeometry extends Shape3D{
	createGeometry(){
		int m=4;
		int n=5;
		float x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
		Point3f[] pts = new Point3f[(m-1)*(n-1)*4];
		int index = 0;
		//
		float[][][] p = {{{-1.2f,0.7f,-1.2f},
						  {-0.2f,0.9f,-1.3f},
						  {1.2f,0.9f,-1.3f }
						  },
						 {{-1.2f,-0.7f,-0.6f},
						 {-0.2f,0.2f,-0.5f},
						 {0.2f,-0.8f,-0.4f},
						 {1.2f,0.3f,-0.6f},
						 },
						 {{-1.2f,0.9f,0.1f},
						 {-0.2f,0.3f,0.1f},
						 {0.2f,0.8f,0.f},
						 {1.2f,0.2f,0.1f },
						 },
						 {{-1.2f,0.8f,0.5f},
						 {-0.2f,-0.2f,0.6f},
						 {0.2f,-0.8f,0.5f},
						 {1.2f,-0.1f,0.6f },
						 },
						 {{-1.3f,0.2f,1.2f},
						 {-0.2f,0.9f,1.1f},
						 {0.2f,0.3f,1.3f},
						 {1.3f,0.9f,1.2f},
						 }
		};
		//
		for(int i = 0; i<n-1; i++){
			for(int j = 0; j<m-1; j++){
				x1 = p[i][j][0];
				y1 = p[i][j][1];
				z1 = p[i][j][2];
				pts[index++] = new Point3f(x1,y1,z1);
				x2 = p[i+1][j][0];
				y2 = p[i+1][j][1];
				z2 = p[i+1][j][2];
				pts[index++] = new Point3f(x2,y2,z2);
				x3 = p[i+1][j+1][0];
				y3 = p[i+1][j+1][1];
				z3 = p[i+1][j+1][2];
				pts[index++] = new Point3f(x3,y3,z3);
				x4 = p[i][j][0];
				y4 = p[i][j][1];
				z4 = p[i][j][2];
				pts[index++] = new Point3f(x4,y4,z4);
			}
		}
		//
		//
		int[] coords = new int[4*(m-1)*(n-1)];
		for(int i = 0;i<(m-1)*(n-1)*4;i++){
			coords[i]=i;
		}
		//
		int[] stripCounts = new int[(m-1)*(n-1)];
		for(int i=0;i<(m-1)*(n-1);i++){
			stripCounts[i]=4;
		}
		GeometryInfo gi = new GeometryInfo(GeometryInfo.POLYGON_ARRAY);
		gi.setCoordinates(pts);
		gi.setCoordinateIndices(coords);
		gi.setStripCounts(stripCounts);
		//
		//
		NormalGenerator ng = new NormalGenerator();
		ng.generateNormals(gi);
		this.addGeometry(gi.getGeometryArray());
		//
		gi.reverse();
		this.addGeometry(gi.getGeometryArray());
		
	}
}
