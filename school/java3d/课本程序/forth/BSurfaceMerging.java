import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.utils.behaviors.mouse.*;
public class BSurfaceMerging extends Applet 
{public BranchGroup createBranchGroupSceneGraph() 
{BranchGroup BranchGroupRoot =new BranchGroup();
BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0); 
Color3f bgColor=new Color3f(1.0f,1.0f,1.0f); 
Background bg=new Background(bgColor);
bg.setApplicationBounds(bounds);
BranchGroupRoot.addChild(bg);
Color3f directionalColor=new Color3f(1.f,1.f,1.f);
Vector3f vec=new Vector3f(0.f,0.f,-1.0f);
DirectionalLight directionalLight=new DirectionalLight(directionalColor,vec);
directionalLight.setInfluencingBounds(bounds);
BranchGroupRoot.addChild(directionalLight);
Transform3D tr=new Transform3D();
tr.setScale(0.85);
TransformGroup transformgroup=new TransformGroup(tr);
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
//定义第一个双三次B样条曲面的16个控制顶点
float[][][] P1={{{-0.8f,0.9f,-0.4f,1.f},
               {-0.2f,0.8f,-0.5f,1.f},
               {0.2f,0.9f,-0.4f,1.f},
               {0.8f,0.8f,-0.5f,1.f}  },
              {{-0.8f,0.7f,-0.4f,1.f},
               {-0.2f,0.6f,0.9f,1.f},
               {0.2f,0.7f,0.8f,1.f},
               {0.8f,0.6f,-0.4f,1.f} },
              {{-0.8f,0.4f,-0.4f,1.f},
               {-0.2f,0.5f,0.8f,1.f},
               {0.2f,0.3f,0.7f,1.f},
               {0.8f,0.4f,-0.5f,1.f}   },
              {{-0.8f,0.f,-0.8f,1.f},
               {-0.2f,0.1f,0.9f,1.f},
               {0.2f,0.f,-0.8f,1.f},
               {0.8f,0.1f,0.9f,1.f} } };
//定义第一个双三次B样条曲面的外观属性
Appearance app1 = new Appearance();
PolygonAttributes polygona1=new PolygonAttributes();
polygona1.setBackFaceNormalFlip(true);
polygona1.setCullFace(PolygonAttributes.CULL_NONE);
//polygona1.setPolygonMode(PolygonAttributes.POLYGON_LINE);
app1.setPolygonAttributes(polygona1);
Color3f color11=new Color3f(1.f,0.f,0.f);
Material material1 = new Material();
material1.setAmbientColor(color11);
material1.setSpecularColor(color11); 
material1.setDiffuseColor(color11);
//material.setEmissiveColor(red);
material1.setShininess(128.f);
app1.setMaterial(material1);
//定义第一个双三次B样条曲面控制顶点网格的外观属性
Appearance app10 = new Appearance();
PolygonAttributes polygona10=new PolygonAttributes();
polygona10.setBackFaceNormalFlip(true);
polygona10.setCullFace(PolygonAttributes.CULL_NONE);
polygona10.setPolygonMode(PolygonAttributes.POLYGON_LINE);
app10.setPolygonAttributes(polygona10);
Color3f color110=new Color3f(0.f,1.f,0.f);
Material material10 = new Material();
material10.setAmbientColor(color110);
material10.setSpecularColor(color110); 
material10.setDiffuseColor(color110);
//material10.setEmissiveColor(red);
material10.setShininess(128.f);
app10.setMaterial(material10);
//定义第二个双三次B样条曲面的16个控制顶点，
//其中的三行控制顶点与前一个曲面相同，这样才能保证两个曲面拼接在一起。
float[][][] P2={{{-0.8f,0.7f,-0.4f,1.f},
               {-0.2f,0.6f,0.9f,1.f},
               {0.2f,0.7f,0.8f,1.f},
               {0.8f,0.6f,-0.4f,1.f} },
              {{-0.8f,0.4f,-0.4f,1.f},
               {-0.2f,0.5f,0.8f,1.f},
               {0.2f,0.3f,0.7f,1.f},
               {0.8f,0.4f,-0.5f,1.f}   },
             {{-0.8f,0.f,-0.8f,1.f},
               {-0.2f,0.1f,0.9f,1.f},
               {0.2f,0.f,-0.8f,1.f},
               {0.8f,0.1f,0.9f,1.f} },
              {{-0.8f,-0.9f,0.4f,1.f},
               {-0.2f,-0.9f,0.6f,1.f},
               {0.2f,-0.8f,0.4f,1.f},
               {0.8f,-0.9f,0.6f,1.f} } };
//定义第二个双三次B样条曲面的外观属性
Appearance app2 = new Appearance();
PolygonAttributes polygona2=new PolygonAttributes();
polygona2.setBackFaceNormalFlip(true);
polygona2.setCullFace(PolygonAttributes.CULL_NONE);
//polygona2.setPolygonMode(PolygonAttributes.POLYGON_LINE);
app2.setPolygonAttributes(polygona2);
Color3f color22=new Color3f(0.f,1.f,0.f);
Material material2 = new Material();
material2.setAmbientColor(color22);
material2.setSpecularColor(color22); 
material2.setDiffuseColor(color22);
//material.setEmissiveColor(red);
material2.setShininess(128.f);
app2.setMaterial(material2);
//定义第二个双三次B样条曲面控制顶点网格的外观属性
Appearance app20 = new Appearance();
PolygonAttributes polygona20=new PolygonAttributes();
polygona20.setBackFaceNormalFlip(true);
polygona20.setCullFace(PolygonAttributes.CULL_NONE);
polygona20.setPolygonMode(PolygonAttributes.POLYGON_LINE);
app20.setPolygonAttributes(polygona20);
Color3f color220=new Color3f(0.f,1.f,0.f);
Material material20 = new Material();
material20.setAmbientColor(color220);
material20.setSpecularColor(color220); 
material20.setDiffuseColor(color220);
//material20.setEmissiveColor(red);
material20.setShininess(128.f);
app20.setMaterial(material20);
Shape3D BSurfaceface1=new BThreeOrderSurfaceface(P1,app1);
transformgroup.addChild(BSurfaceface1); 
Shape3D BSurfaceface2=new BThreeOrderSurfaceface(P2,app2);
transformgroup.addChild(BSurfaceface2);     
Shape3D BControlPoints1=new BSurfaceControlPoints(P1,app10); 
transformgroup.addChild(BControlPoints1);  
Shape3D BControlPoints2=new BSurfaceControlPoints(P2,app20); 
transformgroup.addChild(BControlPoints2);  
BranchGroupRoot.compile();
return BranchGroupRoot;
}
public BSurfaceMerging() 
{setLayout(new BorderLayout());
GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
Canvas3D c=new Canvas3D(gc);
add("Center",c);
BranchGroup BranchGroupScene=createBranchGroupSceneGraph();
SimpleUniverse u=new SimpleUniverse(c);
u.getViewingPlatform().setNominalViewingTransform();
u.addBranchGraph(BranchGroupScene);
}
public static void main(String[] args) 
{new MainFrame(new BSurfaceMerging(),400,400);}}
