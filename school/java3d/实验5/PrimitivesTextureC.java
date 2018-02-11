import javax.vecmath.*;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import javax.media.j3d.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.image.*;
import java.applet.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.behaviors.mouse.*;
import java.util.BitSet;
public class PrimitivesTextureC extends Applet implements ActionListener
 {public static void main(String[] args)
  { new MainFrame(new PrimitivesTextureC(), 640, 680);}
    String filename;
    BitSet mask=null;
    Switch switchgroup=null;
  public void init()
  { setLayout(new BorderLayout());
Panel p = new Panel();
p.add(new Label("name:cck,number:20151681310210"));
add(p, BorderLayout.NORTH);
    Panel panel = new Panel();
    panel.setLayout(new GridLayout(1,4));
    add(panel, BorderLayout.SOUTH);
    Button button = new Button("SPHERE");
    button.addActionListener(this);
    panel.add(button);
    button = new Button("CYLINDER");
    button.addActionListener(this);
    panel.add(button);
    button = new Button("BOX");
    button.addActionListener(this);
    panel.add(button);
    button = new Button("CONE");
    button.addActionListener(this);
    panel.add(button);
    GraphicsConfiguration gc=SimpleUniverse.getPreferredConfiguration();
    Canvas3D cv = new Canvas3D(gc);
    setLayout(new BorderLayout());
    add(cv, BorderLayout.CENTER);
    BranchGroup bg = createSceneGraph();
    bg.compile();
    SimpleUniverse su = new SimpleUniverse(cv);
    su.getViewingPlatform().setNominalViewingTransform();
    su.addBranchGraph(bg);
  }
 BranchGroup createSceneGraph()
   {BranchGroup BranchGroupRoot = new BranchGroup();
    BranchGroupRoot.setCapability(BranchGroup.ALLOW_CHILDREN_WRITE);
    Transform3D t=new Transform3D();
    t.setTranslation(new Vector3f(0.f,0.1f,0.f));
    TransformGroup transformgroup= new TransformGroup(t);
    transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
    transformgroup.setCapability(TransformGroup.ALLOW_CHILDREN_WRITE);
    transformgroup.setCapability(TransformGroup.ALLOW_CHILDREN_EXTEND);
    BranchGroupRoot.addChild(transformgroup);
    BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0); 
    Background background = new Background(1.0f, 1.0f, 1.0f);
    background.setApplicationBounds(bounds);
    BranchGroupRoot.addChild(background);
    MouseRotate mouserotate = new MouseRotate();
    mouserotate.setTransformGroup(transformgroup);
    BranchGroupRoot.addChild(mouserotate); 
    mouserotate.setSchedulingBounds(bounds);
    filename="earth.jpg";
    Appearance app = createTextureAppearance(filename);
    Sphere shape1 = new Sphere(0.8f, Sphere.GENERATE_NORMALS
    	  |Sphere.GENERATE_TEXTURE_COORDS, 100, app);
    filename="niao.jpg";
    app=createTextureAppearance(filename);
    Cylinder shape2=new Cylinder(0.7f,1.3f,Cylinder.GENERATE_NORMALS
     	|Cylinder.GENERATE_TEXTURE_COORDS,200,200,app);
   	filename="shuimu.jpg";
    app=createTextureAppearance(filename);
    Box shape3=new Box(0.6f,0.6f,0.6f,Box.GENERATE_NORMALS
   	    |Box.GENERATE_TEXTURE_COORDS,app);
    filename="muai.jpg";
    app=createTextureAppearance(filename);
    Cone shape4=new Cone(0.9f,1.f,Cone.GENERATE_NORMALS
    	  |Cone.GENERATE_TEXTURE_COORDS,200,200,app);
    switchgroup=new Switch();
    switchgroup.setWhichChild(switchgroup.CHILD_MASK);
    switchgroup.setCapability(switchgroup.ALLOW_SWITCH_WRITE);
    switchgroup.addChild(shape1);
    switchgroup.addChild(shape2);
    switchgroup.addChild(shape3);
    switchgroup.addChild(shape4);
    mask=new BitSet();
    mask.set(0);
    switchgroup.setChildMask(mask);
    switchgroup.setWhichChild(Switch.CHILD_MASK);
    transformgroup.addChild(switchgroup);
    return BranchGroupRoot;
 }
Appearance createTextureAppearance(String image0)
{   Appearance app = new Appearance();
    TextureLoader loader = new TextureLoader(image0, this);
    ImageComponent2D image = loader.getImage();
    Texture2D texture = new Texture2D(Texture.BASE_LEVEL,Texture.RGBA,
    image.getWidth(), image.getHeight());
    texture.setImage(0, image);
    texture.setEnable(true);
    texture.setMagFilter(Texture.BASE_LEVEL_LINEAR);
    texture.setMinFilter(Texture.BASE_LEVEL_LINEAR);
    app.setTexture(texture);
    return app;
  }
  public void actionPerformed(ActionEvent e) 
  { String cmd = e.getActionCommand();
    mask=new BitSet();
    if ("SPHERE".equals(cmd))	{mask.set(0);} 
    else if ("CYLINDER".equals(cmd)) {mask.set(1);} 
    else if ("BOX".equals(cmd)) {mask.set(2);} 
    else if ("CONE".equals(cmd)) {mask.set(3);} 
    switchgroup.setChildMask(mask);
    switchgroup.setWhichChild(Switch.CHILD_MASK);
    }  }
