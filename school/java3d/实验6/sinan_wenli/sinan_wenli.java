import java.applet.Applet;
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
public class sinan_wenli extends Applet { 
    public static void main(String[] args){
        new MainFrame(new sinan_wenli(), 750, 730);
    }

    public void init(){   
        Panel p = new Panel();
        p.add(new Label("name:cck,number:20151681310210 sinan_wenli"));
        add(p, BorderLayout.NORTH);
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
  
    private BranchGroup createSceneGraph() {
BranchGroup BranchGroupRoot=new BranchGroup();
    BoundingSphere bounds=new BoundingSphere(new Point3d(0.0,0.0,0.0),100.0); 
    Color3f bgColor=new Color3f(1.0f,1.0f,1.0f); 
    Background bg=new Background(bgColor);
    bg.setApplicationBounds(bounds);
    BranchGroupRoot.addChild(bg);

    Color3f directionalColor=new Color3f(1.f,0.f,0.f);
    Vector3f vec=new Vector3f(0.f,0.f,-1.0f);
    DirectionalLight directionalLight=new DirectionalLight(directionalColor,vec);
    directionalLight.setInfluencingBounds(bounds);
    BranchGroupRoot.addChild(directionalLight);
    
    Transform3D tr = new Transform3D();
    tr.setScale(0.85);
    TransformGroup transformgroup=new TransformGroup(tr);
    transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
    transformgroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
    BranchGroupRoot.addChild(transformgroup);

    MouseRotate mouserotate=new MouseRotate();
    mouserotate.setTransformGroup(transformgroup);
    BranchGroupRoot.addChild(mouserotate); 
    mouserotate.setSchedulingBounds(bounds);
    
    MouseZoom mousezoom = new MouseZoom();
    mousezoom.setTransformGroup(transformgroup);
    BranchGroupRoot.addChild(mousezoom);
    mousezoom.setSchedulingBounds(bounds);
    
    MouseTranslate mousetranslate=new MouseTranslate();
    mousetranslate.setTransformGroup(transformgroup);
    BranchGroupRoot.addChild(mousetranslate);
    mousetranslate.setSchedulingBounds(bounds);

       
        
        float[][][] P1={{{       +0.0f,+0.15f,+0.4f,1.f},
                            {+0.0f,+0.25f,-0.0f,1.f},
                            {+0.0f,+0.35f,-0.0f,1.f},
                            {+0.0f,+0.45f,+0.4f,1.f}  },
            {               {+0.6f,-0.6f,+0.4f,1.f},
                            {+0.6f,+0.2f,-0.4f,1.f},
                            {+0.6f,+0.4f,-0.4f,1.f},
                            {+0.6f,+1.2f,+0.4f,1.f} },
            {               {+1.2f,-0.6f,+0.4f,1.f},
                            {+1.2f,+0.2f,-0.4f,1.f},
                            {+1.2f,+0.4f,-0.4f,1.f},
                            {+1.2f,+1.2f,+0.4f,1.f}   },
            {               {+1.8f,+0.0f,+0.4f,1.f},
                            {+2.0f,+0.2f,+0.4f,1.f},
                            {+2.0f,+0.4f,+0.4f,1.f},
                            {+1.8f,+0.6f,+0.4f,1.f} } };
	float[][][] P2={{{      +0.0f,+0.15f,+0.4f,1.f},
                            {+0.0f,+0.25f,-0.0f,1.f},
                            {+0.0f,+0.35f,-0.0f,1.f},
                            {+0.0f,+0.45f,+0.4f,1.f}  },
            {               {-0.8f,+0.1f,+0.6f,1.f},
                            {-0.8f,+0.23f,+0.5f,1.f},
                            {-0.8f,+0.36f,+0.5f,1.f},
                            {-0.8f,+0.5f,+0.6f,1.f} },
            {               {-1.6f,+0.1f,+1.2f,1.f},
                            {-1.6f,+0.23f,+1.1f,1.f},
                            {-1.6f,+0.36f,+1.1f,1.f},
                            {-1.6f,+0.5f,+1.2f,1.f}   },
            {               {-2.4f,+0.1f,+1.8f,1.f},
                            {-2.9f,+0.23f,+1.8f,1.f},
                            {-2.9f,+0.36f,+1.8f,1.f},
                            {-2.4f,+0.5f,+1.8f,1.f} } };
	float[][][] P3={{{     -4.2f,-5.0f,+0.2f,1.f},
                            {-4.2f,-1.0f,+0.2f,1.f},
                            {-4.2f,+1.0f,+0.2f,1.f},
                            {-4.2f,+5.0f,+0.2f,1.f}  },
            {               {-0.2f,-5.0f,+0.2f,1.f},
                            {-0.2f,-1.0f,-0.4f,1.f},
                            {-0.2f,+1.0f,-0.4f,1.f},
                            {-0.2f,+5.0f,+0.2f,1.f} },
            {               {+1.8f,-5.0f,+0.2f,1.f},
                            {+1.8f,-1.0f,-0.4f,1.f},
                            {+1.8f,+1.0f,-0.4f,1.f},
                            {+1.8f,+5.0f,+0.2f,1.f}   },
            {               {+5.8f,-5.0f,+0.2f,1.f},
                            {+5.8f,-1.0f,+0.2f,1.f},
                            {+5.8f,+1.0f,+0.2f,1.f},
                            {+5.8f,+5.0f,+0.2f,1.f} } };
        
Appearance app = new Appearance();
        TextureLoader loader = new TextureLoader("index.jpeg",2, this);
        ImageComponent2D image = loader.getImage();
        Texture2D texture = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
              image.getWidth(), image.getHeight());
    texture.setImage(0, image);
    texture.setEnable(true);
    //texture.setMagFilter(Texture.BASE_LEVEL_LINEAR);
    texture.setMinFilter(Texture.BASE_LEVEL_LINEAR);
    app.setTexture(texture);
    PolygonAttributes polygonattributes=new PolygonAttributes();
    polygonattributes.setBackFaceNormalFlip(true);
  	polygonattributes.setCullFace(PolygonAttributes.CULL_NONE);
  	app.setPolygonAttributes(polygonattributes);
    app.setCapability(Appearance.ALLOW_TEXGEN_WRITE);
    
 Appearance app1 = new Appearance();
        TextureLoader loader1 = new TextureLoader("index6.jpg",2, this);
        ImageComponent2D image1 = loader1.getImage();
        Texture2D texture1 = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
              image1.getWidth(), image1.getHeight());
    texture1.setImage(0, image1);
    texture1.setEnable(true);
    //texture.setMagFilter(Texture.BASE_LEVEL_LINEAR);
    texture1.setMinFilter(Texture.BASE_LEVEL_LINEAR);
    app1.setTexture(texture1);
    PolygonAttributes polygonattributes1=new PolygonAttributes();
    polygonattributes1.setBackFaceNormalFlip(true);
  	polygonattributes1.setCullFace(PolygonAttributes.CULL_NONE);
  	app1.setPolygonAttributes(polygonattributes1);
    app1.setCapability(Appearance.ALLOW_TEXGEN_WRITE);
      

      Transform3D t = new Transform3D();
      TransformGroup temp = new TransformGroup();
      temp.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
      temp.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
      t.setTranslation(new Vector3f(0.f,0.3f,0.f));
      Shape3D BezierSurfaceface1=new BezierThreeOrderSurfaceface(P1,app);
      temp.addChild(BezierSurfaceface1); 
      Shape3D BezierSurfaceface2=new BezierThreeOrderSurfaceface(P2,app);
      temp.addChild(BezierSurfaceface2);     
      //Shape3D BezierControlPoints1=new BezierSurfaceControlPoints(P1,app2); 
      //temp.addChild(BezierControlPoints1);  
      //Shape3D BezierControlPoints2=new BezierSurfaceControlPoints(P2,app1); 
      //temp.addChild(BezierControlPoints2);  

	   t = new Transform3D();
        TransformGroup transformGroup22 = new TransformGroup(t);
        transformGroup22.addChild(temp);
        Alpha rotationAlpha22=new Alpha(-1,Alpha.INCREASING_ENABLE,0,0,5000,0,0,5000,0,0);
        Transform3D zAxis22 = new Transform3D();
        zAxis22.rotX(-Math.PI/2);
        zAxis22.setTranslation(new Vector3f(0.8f, 0.3f, 0.0f));
        RotationInterpolator rotator22=new RotationInterpolator(rotationAlpha22,temp, zAxis22, 0.0f, (float)Math.PI*2.0f);
        rotator22.setSchedulingBounds(bounds);
        transformGroup22.addChild(rotator22);
        transformgroup.addChild(transformGroup22);  



      
      Shape3D BezierSurfaceface3=new BezierThreeOrderSurfaceface(P3,app1);
      transformgroup.addChild(BezierSurfaceface3);  
      //Shape3D BezierControlPoints3=new BezierSurfaceControlPoints(P3,app3); 
      //transformgroup.addChild(BezierControlPoints3);  
    return BranchGroupRoot;
  }} 
class  BezierThreeOrderSurfaceface extends Shape3D 
{public BezierThreeOrderSurfaceface(float[][][] P,Appearance app) 
{int i,j,k;
int n0;
float division;
n0=50;division=1.f/n0;

float[][] PX=new float[4][4];
float[][] PY=new float[4][4];
float[][] PZ=new float[4][4];
float[][] P4=new float[4][4];

float[][] M1={{1.f,0.f,0.f,0.f},
             {-3.f,3.f,0.f,0.f},
             {3.f,-6.f,3.f,0.f},
             {-1.f,3.f,-3.f,1.f} };
float[][] M2={{1.f,-3.f,3.f,-1.f},
             {0.f,3.f,-6.f,3.f},
             {0.f,0.f,3.f,-3.f},
             {0.f,0.f,0.f,1.f} };
float[][][] UV=new float[n0+1][n0+1][2];
float[][] UU=new float[1][4];
float[][] VV=new float[4][1];
float[][][] SurfaceXYZ=new float[n0+1][n0+1][4];
 for(i=0;i<n0+1;i++)
    for(j=0;j<n0+1;j++)
    {	UV[i][j][0]=i*division;
     	UV[i][j][1]=j*division;}	
 for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    { PX[i][j]=P[i][j][0];
      PY[i][j]=P[i][j][1];
      PZ[i][j]=P[i][j][2];
      P4[i][j]=P[i][j][3];}	
 for(i=0;i<n0+1;i++)
   for(j=0;j<n0+1;j++)
   {UU[0][0]=1.f;
    UU[0][1]=UV[i][j][0];
    UU[0][2]=UV[i][j][0]*UV[i][j][0];
    UU[0][3]=UV[i][j][0]*UV[i][j][0]*UV[i][j][0];
    VV[0][0]=1.f;
    VV[1][0]=UV[i][j][1];
    VV[2][0]=UV[i][j][1]*UV[i][j][1];
    VV[3][0]=UV[i][j][1]*UV[i][j][1]*UV[i][j][1];
    matrixm g0=new matrixm(1,4,4,UU,M1);
    matrixm g1=new matrixm(1,4,4,g0.CC,PX);
    matrixm g2=new matrixm(1,4,4,g1.CC,M2);
    matrixm g3=new matrixm(1,4,1,g2.CC,VV);
    SurfaceXYZ[i][j][0]=g3.CC[0][0];
    matrixm g4=new matrixm(1,4,4,UU,M1);
    matrixm g5=new matrixm(1,4,4,g4.CC,PY);
    matrixm g6=new matrixm(1,4,4,g5.CC,M2);
    matrixm g7=new matrixm(1,4,1,g6.CC,VV);
    SurfaceXYZ[i][j][1]=g7.CC[0][0];
    matrixm g8=new matrixm(1,4,4,UU,M1);
    matrixm g9=new matrixm(1,4,4,g8.CC,PZ);
    matrixm g10=new matrixm(1,4,4,g9.CC,M2);
    matrixm g11=new matrixm(1,4,1,g10.CC,VV);
    SurfaceXYZ[i][j][2]=g11.CC[0][0];
    matrixm g12=new matrixm(1,4,4,UU,M1);
    matrixm g13=new matrixm(1,4,4,g12.CC,P4);
    matrixm g14=new matrixm(1,4,4,g13.CC,M2);
    matrixm g15=new matrixm(1,4,1,g14.CC,VV);
    SurfaceXYZ[i][j][3]=g15.CC[0][0];
    SurfaceXYZ[i][j][0]=SurfaceXYZ[i][j][0]/SurfaceXYZ[i][j][3];
    SurfaceXYZ[i][j][1]=SurfaceXYZ[i][j][1]/SurfaceXYZ[i][j][3];
    SurfaceXYZ[i][j][2]=SurfaceXYZ[i][j][2]/SurfaceXYZ[i][j][3];
    }	
QuadArray BezierQuadsurfaceface=new QuadArray(n0*n0*4,GeometryArray.COORDINATES|GeometryArray.NORMALS|GeometryArray.TEXTURE_COORDINATE_2);
int c=0;	
for(i=0;i<n0;i++) 
{for(j=0;j<n0;j++)
{
Point3f A=new Point3f(SurfaceXYZ[i][j][0],
SurfaceXYZ[i][j][1],SurfaceXYZ[i][j][2]);
Point3f B=new Point3f(SurfaceXYZ[i+1][j][0],
SurfaceXYZ[i+1][j][1],SurfaceXYZ[i+1][j][2]);
Point3f C=new Point3f(SurfaceXYZ[i+1][j+1][0],
SurfaceXYZ[i+1][j+1][1],SurfaceXYZ[i+1][j+1][2]);
Point3f D=new Point3f(SurfaceXYZ[i][j+1][0],
SurfaceXYZ[i][j+1][1],SurfaceXYZ[i][j+1][2]);
Vector3f a = new Vector3f(A.x - B.x, A.y - B.y, A.z - B.z);
Vector3f b = new Vector3f(C.x - B.x, C.y - B.y, C.z - B.z);
Vector3f n = new Vector3f();
n.cross(b, a);
n.normalize();
BezierQuadsurfaceface.setCoordinate(c, A);
BezierQuadsurfaceface.setCoordinate(c+1, B);
BezierQuadsurfaceface.setCoordinate(c+2, C);
BezierQuadsurfaceface.setCoordinate(c+3, D);
BezierQuadsurfaceface.setNormal(c, n);
BezierQuadsurfaceface.setNormal(c+1, n);
BezierQuadsurfaceface.setNormal(c+2, n);
BezierQuadsurfaceface.setNormal(c+3, n);
TexCoord2f texCoords=new TexCoord2f(i*1.f/n0,1.f-j*1.f/n0);	
BezierQuadsurfaceface.setTextureCoordinate(0,c,texCoords);
texCoords=new TexCoord2f((i+1)*1.f/n0,1.f-j*1.f/n0);	
BezierQuadsurfaceface.setTextureCoordinate(0,c+1,texCoords);	
texCoords=new TexCoord2f((i+1)*1.f/n0,1.f-(j+1)*1.f/n0);	
BezierQuadsurfaceface.setTextureCoordinate(0,c+2,texCoords);
texCoords=new TexCoord2f(i*1.f/n0,1.f-(j+1)*1.f/n0);	
BezierQuadsurfaceface.setTextureCoordinate(0,c+3,texCoords);
c=c+4;
}}
this.addGeometry(BezierQuadsurfaceface);
this.setAppearance(app);
}}

class matrixm{	
 	public float CC[][]= new float[4][4];
	int ll,mm,kk;
	public matrixm(int mmm, int kkk, int nnn,float a[][],float b[][]){
		for(ll=0;ll<mmm;ll++)
            for(mm=0;mm<nnn;mm++){
                CC[ll][mm]=0.f;
            }

        for(ll=0;ll<mmm;ll++)
            for(mm=0;mm<nnn;mm++){   
                for(kk=0;kk<kkk;kk++)
                CC[ll][mm]=CC[ll][mm]+a[ll][kk]*b[kk][mm];  
            } 
    }
}
