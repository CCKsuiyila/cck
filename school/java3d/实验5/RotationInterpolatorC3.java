import java.applet.Applet;
import java.awt.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.utils.behaviors.mouse.*;
import java.awt.GraphicsConfiguration;


public class RotationInterpolatorC3 extends Applet
{public BranchGroup createBranchGroupSceneGraph()
{BranchGroup BranchGroupRoot = new BranchGroup();
BoundingSphere bounds = new BoundingSphere(new Point3d(0.0,0.0,0.0),100);
Color3f bgColor = new Color3f(1.0f,1.0f,1.0f);
Background bg = new Background(bgColor);
bg.setApplicationBounds(bounds);
BranchGroupRoot.addChild(bg);
//定义平行光
Color3f directionalColor = new Color3f(1.f,1.f,0.9f);
Vector3f vec = new Vector3f(4.0f, -7.0f, -12.0f);
DirectionalLight directionalLight = new DirectionalLight(directionalColor,vec);
directionalLight.setInfluencingBounds(bounds);
BranchGroupRoot.addChild(directionalLight);
//定义总的变换
Transform3D t1 = new Transform3D();
t1.setScale(0.8);
TransformGroup transformGroup = new TransformGroup(t1);
transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
BranchGroupRoot.addChild(transformGroup);
//定义鼠标旋转对象
MouseRotate mouseRotate = new MouseRotate();
mouseRotate.setTransformGroup(transformGroup);
BranchGroupRoot.addChild(mouseRotate);
mouseRotate.setSchedulingBounds(bounds);
Transform3D t = new Transform3D();
t = new Transform3D();
t.setTranslation(new Vector3f(-0.f,0.f,0.0f));
TransformGroup transformGroup1 = new transformGroup(t);
transformGroup1.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup1.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
Alpha rotationAlpha1=new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,7000,0,0,7000,0,0);
Transform3D zAxis1 = new Transform3D();
Vector3d Eulor1=new Vector3d(Math.PI/4,Math.PI/4,0.);
zAxis1.setEuler(Eulor1);
RotationInterpolator rotator1=new RotationInterpolator(rotationAlpha1,transformGroup1,zAxis1,0.0f,(float)Math.PI*2.0f);
rotator1.setSchedulingBounds(bounds);
transformGroup1.addChild(rotator1);
t = new Transform3D();
t.setTranslation(new Vector3f(-0.8f,0.8f,0.0f));
TransformGroup transformGroup2 = new transformGroup(t);
transformGroup2.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup2.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
Alpha rotationAlpha2 = new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
Transform3D zAxis2 = new Transform3D();
Vector3d Eulor2=new Vector3d(Math.PI/4,Math.PI/4,0.);
zAxis2.setEuler(Eulor2);
zAxis2.setTranslation(new Vector3f(-.8f, .8f, 0.0f));
RotationInterpolator rotator2 =	new RotationInterpolator(rotationAlpha2,transformGroup2, zAxis2, 0.0f, (float)Math.PI*2.0f);
rotator2.setSchedulingBounds(bounds);
transformGroup2.addChild(rotator2);
t = new Transform3D();
t.setTranslation(new Vector3f(0.8f,0.8f,0.0f));
TransformGroup transformGroup3 = new transformGroup(t);
transformGroup3.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup3.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
Alpha rotationAlpha3 = new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
Transform3D zAxis3 = new Transform3D();
zAxis3.setTranslation(new Vector3f(.8f, .8f, 0.0f));
RotationInterpolator rotator3 =	new RotationInterpolator(rotationAlpha3,transformGroup3, zAxis3, 0.0f, (float)Math.PI*2.0f);
rotator3.setSchedulingBounds(bounds);
transformGroup3.addChild(rotator3);
t = new Transform3D();
TransformGroup transformGroup22 = new TransformGroup(t);
transformGroup22.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup22.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
transformGroup22.addChild(transformGroup2);
Alpha rotationAlpha22=new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
Transform3D zAxis22 = new Transform3D();
zAxis22.rotZ(-Math.PI/4);
zAxis22.setTranslation(new Vector3f(0.f, 0.f, 0.0f));
RotationInterpolator rotator22=new RotationInterpolator(rotationAlpha22,transformGroup22, zAxis22, 0.0f, (float)Math.PI*2.0f);
rotator22.setSchedulingBounds(bounds);
transformGroup22.addChild(rotator22);
t = new Transform3D();
TransformGroup transformGroup33 = new TransformGroup(t);
transformGroup33.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup33.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
transformGroup33.addChild(transformGroup3);
Alpha rotationAlpha33 = new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
Transform3D zAxis33 = new Transform3D();
zAxis33.rotZ(Math.PI/4);
zAxis33.setTranslation(new Vector3f(0.f, 0.f, 0.0f));
RotationInterpolator rotator33 =new RotationInterpolator(rotationAlpha33,transformGroup33, zAxis33, 0.0f, (float)Math.PI*2.0f);
rotator33.setSchedulingBounds(bounds);
transformGroup33.addChild(rotator33);
transformGroup.addChild(transformGroup1);
transformGroup.addChild(transformGroup22);
transformGroup.addChild(transformGroup33);
BranchGroupRoot.compile();
return BranchGroupRoot;
}
public RotationInterpolatorC3()
{setLayout(new BorderLayout());
Panel p = new Panel();
p.add(new Label("name:cck,number:20151681310210"));
add(p, BorderLayout.NORTH);
GraphicsConfiguration config=SimpleUniverse.getPreferredConfiguration();
Canvas3D c=new Canvas3D(config);
add("Center",c);		
BranchGroup BranchGroupScene = createBranchGroupSceneGraph();		
SimpleUniverse u = new SimpleUniverse(c);
u.getViewingPlatform().setNominalViewingTransform();
u.addBranchGraph(BranchGroupScene);
}	
public static void main(String[] args)
{new MainFrame(new RotationInterpolatorC3(),550,550);}
}
class transformGroup extends TransformGroup
{public transformGroup(Transform3D tt)
{TransformGroup transformGroup0 = new TransformGroup(tt);
transformGroup0.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
transformGroup0.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
Appearance app1 = new Appearance();
Material material1 = new Material();
material1.setDiffuseColor(new Color3f(1.0f,0.0f,0.0f));
app1.setMaterial(material1);
Appearance app2 = new Appearance();
Material material2 = new Material();
material2.setDiffuseColor(new Color3f(0.f,1.f,0.f));
app2.setMaterial(material2);
Appearance app3 = new Appearance();
Material material3 = new Material();
material3.setDiffuseColor(new Color3f(0.f,0.f,1.f));
app3.setMaterial(material3);
Appearance app4 = new Appearance();
Material material4 = new Material();
material4.setDiffuseColor(new Color3f(1.f,1.f,0.f));
app4.setMaterial(material4);
//定义基本体及外观属性与坐标变换
Transform3D t = new Transform3D();
t.setTranslation(new Vector3f(0.f,0.0f,0.0f));
TransformGroup tg1 = new TransformGroup(t);
tg1.addChild(new Sphere(0.2f, Sphere.GENERATE_NORMALS,1000,app1));
t = new Transform3D();
t.setTranslation(new Vector3f(0.f,0.0f,0.0f));
TransformGroup tg2 = new TransformGroup(t);
tg2.addChild(new Cylinder(0.1f,0.5f,Cylinder.GENERATE_NORMALS,120, 120,app2));
t = new Transform3D();
t.rotX(Math.PI/2);
t.setTranslation(new Vector3f(0.f,0.0f,0.0f));
TransformGroup tg3 = new TransformGroup(t);
tg3.addChild(new Cylinder(0.1f,.5f,Cylinder.GENERATE_NORMALS,120, 120,app3));
t = new Transform3D();
t.rotZ(Math.PI/2);
t.setTranslation(new Vector3f(0.f,0.0f,0.0f));
TransformGroup tg4 = new TransformGroup(t);
tg4.addChild(new Cylinder(0.1f,0.5f,Cylinder.GENERATE_NORMALS,120, 120,app4));
transformGroup0.addChild(tg1);
transformGroup0.addChild(tg2);
transformGroup0.addChild(tg3);
transformGroup0.addChild(tg4);
this.addChild(transformGroup0);}}
