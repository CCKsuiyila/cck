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
public class BezierSurfaceTextureNew extends Applet 
{ public static void main(String[] args)
   {new MainFrame(new BezierSurfaceTextureNew(), 750, 730);}
public void init()
{   Panel p = new Panel();
p.add(new Label("name:cck,number:20151681310210"));
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
  private BranchGroup createSceneGraph() 
   {BranchGroup BranchGroupRoot = new BranchGroup();
    Transform3D t = new Transform3D();
    TransformGroup trans= new TransformGroup(t);
    trans.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
    BranchGroupRoot.addChild(trans);
    BoundingSphere bounds = new BoundingSphere();
    //定义鼠标旋转 
    MouseRotate mouserotate = new MouseRotate();
    mouserotate.setTransformGroup(trans);
    BranchGroupRoot.addChild(mouserotate); 
    mouserotate.setSchedulingBounds(bounds);
    //定义背景
    Background background = new Background(1.0f, 1.0f, 1.0f);
    background.setApplicationBounds(bounds);
    BranchGroupRoot.addChild(background);
    //定义Bezier曲面的16个控制顶点
float[][][] P1={{{-1.3f,-0.9f,-0.8f,1.f},
                 {-0.2f,-0.8f,0.9f,1.f},
                 {0.2f,-0.9f,-0.8f,1.f},
                 {0.8f,-0.8f,0.44f,1.f} },
                {{-0.8f,-0.4f,-0.4f,1.f},
                 {-0.2f,-0.5f,0.8f,1.f},
                 {0.2f,-0.3f,0.7f,1.f},
                 {0.8f,-0.4f,-0.5f,1.f} },
                {{-0.8f,0.4f,-0.4f,1.f},
                 {-0.2f,0.3f,0.9f,1.f},
                 {0.2f,0.4f,0.8f,1.f},
                 {0.8f,0.3f,-0.4f,1.f} }, 
                {{-1.2f,1.2f,-0.8f,1.f},
                 {-0.2f,0.7f,-0.5f,1.f},
                 {0.2f,0.6f,-0.9f,1.f},
                 {1.f,1.1f,-0.5f,1.f}  }};
    Appearance app = new Appearance();
    TextureLoader loader = new TextureLoader("maotouying.jpg",2, this);
    ImageComponent2D image = loader.getImage();
    Texture2D texture = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
              image.getWidth(), image.getHeight());
    texture.setImage(0, image);
    texture.setEnable(true);
    //设置纹理的放大与缩小过滤
    //texture.setMagFilter(Texture.BASE_LEVEL_LINEAR);
    texture.setMinFilter(Texture.BASE_LEVEL_LINEAR);
    app.setTexture(texture);
    PolygonAttributes polygonattributes=new PolygonAttributes();
    polygonattributes.setBackFaceNormalFlip(true);
  	polygonattributes.setCullFace(PolygonAttributes.CULL_NONE);
  	app.setPolygonAttributes(polygonattributes);
    app.setCapability(Appearance.ALLOW_TEXGEN_WRITE);
    Shape3D BezierSurfaceface=new BezierThreeOrderSurfaceface(P1,app);
    trans.addChild(BezierSurfaceface); 
    //设置旋转插值
    Alpha alpha = new Alpha(-1, 6000);
    RotationInterpolator rotator=new RotationInterpolator(alpha, trans);
    rotator.setSchedulingBounds(bounds);
    trans.addChild(rotator);
    return BranchGroupRoot;
  }} 
class  BezierThreeOrderSurfaceface extends Shape3D 
{public BezierThreeOrderSurfaceface(float[][][] P,Appearance app) 
{int i,j,k;
int n0;//定义对参数u、v在[0，1]区间的等分点数
float division;//参数u在[0，1]区间的等分线段长度
n0=50;division=1.f/n0;
//分别定义存放控制顶点x、y、z坐标与第四维坐标的数组
float[][] PX=new float[4][4];
float[][] PY=new float[4][4];
float[][] PZ=new float[4][4];
float[][] P4=new float[4][4];
//定义系数矩阵及其转置矩阵
float[][] M1={{1.f,0.f,0.f,0.f},
             {-3.f,3.f,0.f,0.f},
             {3.f,-6.f,3.f,0.f},
             {-1.f,3.f,-3.f,1.f} };
float[][] M2={{1.f,-3.f,3.f,-1.f},
             {0.f,3.f,-6.f,3.f},
             {0.f,0.f,3.f,-3.f},
             {0.f,0.f,0.f,1.f} };
//定义Bezier曲面的u、v参数分割点坐标数组
float[][][] UV=new float[n0+1][n0+1][2];
//定义U、V矩阵数组
float[][] UU=new float[1][4];
float[][] VV=new float[4][1];
//定义存放曲面上点的坐标的数组
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
 //计算曲面上点的坐标值
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
    //计算一点的x坐标
    matrixm g0=new matrixm(1,4,4,UU,M1);
    matrixm g1=new matrixm(1,4,4,g0.CC,PX);
    matrixm g2=new matrixm(1,4,4,g1.CC,M2);
    matrixm g3=new matrixm(1,4,1,g2.CC,VV);
    SurfaceXYZ[i][j][0]=g3.CC[0][0];
    //计算一点的y坐标
    matrixm g4=new matrixm(1,4,4,UU,M1);
    matrixm g5=new matrixm(1,4,4,g4.CC,PY);
    matrixm g6=new matrixm(1,4,4,g5.CC,M2);
    matrixm g7=new matrixm(1,4,1,g6.CC,VV);
    SurfaceXYZ[i][j][1]=g7.CC[0][0];
    //计算一点的z坐标
    matrixm g8=new matrixm(1,4,4,UU,M1);
    matrixm g9=new matrixm(1,4,4,g8.CC,PZ);
    matrixm g10=new matrixm(1,4,4,g9.CC,M2);
    matrixm g11=new matrixm(1,4,1,g10.CC,VV);
    SurfaceXYZ[i][j][2]=g11.CC[0][0];
    //计算一点的第4维坐标
    matrixm g12=new matrixm(1,4,4,UU,M1);
    matrixm g13=new matrixm(1,4,4,g12.CC,P4);
    matrixm g14=new matrixm(1,4,4,g13.CC,M2);
    matrixm g15=new matrixm(1,4,1,g14.CC,VV);
    SurfaceXYZ[i][j][3]=g15.CC[0][0];
    //将齐次坐标转换为三维坐标系坐标，如果第4维为1，则不用除第4维
    SurfaceXYZ[i][j][0]=SurfaceXYZ[i][j][0]/SurfaceXYZ[i][j][3];
    SurfaceXYZ[i][j][1]=SurfaceXYZ[i][j][1]/SurfaceXYZ[i][j][3];
    SurfaceXYZ[i][j][2]=SurfaceXYZ[i][j][2]/SurfaceXYZ[i][j][3];
    }	
QuadArray BezierQuadsurfaceface=new QuadArray(n0*n0*4,GeometryArray.COORDINATES|GeometryArray.NORMALS|GeometryArray.TEXTURE_COORDINATE_2);
int c=0;//以顶点数累加的方式设置顶点的序号	
for(i=0;i<n0;i++) 
{for(j=0;j<n0;j++)
{//设置一个平面上的4个点
Point3f A=new Point3f(SurfaceXYZ[i][j][0],
SurfaceXYZ[i][j][1],SurfaceXYZ[i][j][2]);
Point3f B=new Point3f(SurfaceXYZ[i+1][j][0],
SurfaceXYZ[i+1][j][1],SurfaceXYZ[i+1][j][2]);
Point3f C=new Point3f(SurfaceXYZ[i+1][j+1][0],
SurfaceXYZ[i+1][j+1][1],SurfaceXYZ[i+1][j+1][2]);
Point3f D=new Point3f(SurfaceXYZ[i][j+1][0],
SurfaceXYZ[i][j+1][1],SurfaceXYZ[i][j+1][2]);
//计算由四个点形成的平面的法向量
Vector3f a = new Vector3f(A.x - B.x, A.y - B.y, A.z - B.z);
Vector3f b = new Vector3f(C.x - B.x, C.y - B.y, C.z - B.z);
Vector3f n = new Vector3f();
n.cross(b, a);
n.normalize();
//设置点的序号
BezierQuadsurfaceface.setCoordinate(c, A);
BezierQuadsurfaceface.setCoordinate(c+1, B);
BezierQuadsurfaceface.setCoordinate(c+2, C);
BezierQuadsurfaceface.setCoordinate(c+3, D);
//设置点的法向量
BezierQuadsurfaceface.setNormal(c, n);
BezierQuadsurfaceface.setNormal(c+1, n);
BezierQuadsurfaceface.setNormal(c+2, n);
BezierQuadsurfaceface.setNormal(c+3, n);
//设置纹理坐标
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
