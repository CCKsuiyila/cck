import java.applet.Applet;
import java.awt.*;

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.behaviors.mouse.*;

import javax.media.j3d.*;
import javax.vecmath.*;


public class E4_2 extends Applet {
	public BranchGroup createBranchGroupSceneGraph(){

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
    
        TransformGroup transformgroup=new TransformGroup();
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


        //
        float[][][] P1={{{-0.8f,-1.2f,-0.8f,1.f},
               {-0.2f,0.2f,-0.5f,1.f},
               {0.2f,0.3f,-0.5f,1.f},
               {0.8f,-1.2f,-0.8f,1.f}  },
            {  {-0.8f,-0.1f,-0.2f,1.f},
               {-0.2f,0.9f,-0.2f,1.f},
               {0.2f,0.9f,-0.2f,1.f},
               {0.8f,-0.1f,-0.2f,1.f} },
            {  {-0.8f,-0.1f,0.2f,1.f},
               {-0.2f,0.9f,0.2f,1.f},
               {0.2f,0.9f,0.2f,1.f},
               {0.8f,-0.1f,0.2f,1.f}   },
            {  {-0.6f,-0.6f,0.9f,1.f},
               {-0.2f,0.2f,0.5f,1.f},
               {0.2f,0.3f,0.5f,1.f},
               {0.6f,-0.65f,0.8f,1.f} } };
        //
        Appearance app1 = new Appearance();
        PolygonAttributes polygona1=new PolygonAttributes();
        polygona1.setCullFace(PolygonAttributes.CULL_NONE);
        //polygona1.setPolygonMode(PolygonAttributes.POLYGON_LINE);
        app1.setPolygonAttributes(polygona1);
        ColoringAttributes color1=new ColoringAttributes();
        color1.setColor(0.f,1.f,0.f);
        app1.setColoringAttributes(color1);
        //
        Appearance app2 = new Appearance();
        PolygonAttributes polygona2=new PolygonAttributes();
        polygona2.setCullFace(PolygonAttributes.CULL_NONE);
        //polygona2.setPolygonMode(PolygonAttributes.POLYGON_LINE);
        app2.setPolygonAttributes(polygona2);
        ColoringAttributes color2=new ColoringAttributes();
        color2.setColor(2.f,0.f,0.f);
        app2.setColoringAttributes(color2);

        TransparencyAttributes transparence=new TransparencyAttributes(1,.8f);
        app2.setTransparencyAttributes(transparence);
        Shape3D BezierSurfaceface1=new BezierThreeOrderSurfaceface(P1,app1);
        transformgroup.addChild(BezierSurfaceface1); 
        Shape3D BezierControlPoints1=new BezierSurfaceControlPoints(P1,app2); 
        transformgroup.addChild(BezierControlPoints1);

        BranchGroupRoot.compile();
        return BranchGroupRoot;
    }
    
    public E4_2(){
        setLayout(new BorderLayout());
        Panel p = new Panel();
    	p.add(new Label("name:cck, number:20151681310210"));
    	add(p, BorderLayout.NORTH);
        GraphicsConfiguration gc = SimpleUniverse.getPreferredConfiguration();
        Canvas3D c = new Canvas3D(gc);
        add("Center", c);
        BranchGroup BranchGroupScene = createBranchGroupSceneGraph();
        SimpleUniverse u = new SimpleUniverse(c);
        u.getViewingPlatform().setNominalViewingTransform();
        u.addBranchGraph(BranchGroupScene);
    }
     
    public static void main(String[] args){
	    new MainFrame(new E4_2(),400,400);
	}
}




    //
    class  BezierThreeOrderSurfaceface extends Shape3D {
	    public BezierThreeOrderSurfaceface(float[][][] P,Appearance app){
            int i,j,k;
            int n0;//
            float division;//
            n0=50;division=1.f/n0;
            //
            float[][] PX=new float[4][4];
            float[][] PY=new float[4][4];
            float[][] PZ=new float[4][4];
            float[][] P4=new float[4][4];
            //
            float[][] M1={{1.f,0.f,0.f,0.f},
             {-3.f,3.f,0.f,0.f},
             {3.f,-6.f,3.f,0.f},
             {-1.f,3.f,-3.f,1.f} };
            float[][] M2={{1.f,-3.f,3.f,-1.f},
             {0.f,3.f,-6.f,3.f},
             {0.f,0.f,3.f,-3.f},
             {0.f,0.f,0.f,1.f} };

            //
            float[][][] UV=new float[n0+1][n0+1][2];
            //
            float[][] UU=new float[1][4];
            float[][] VV=new float[4][1];
            //
            float[][][] SurfaceXYZ=new float[n0+1][n0+1][4]; 
            for(i=0;i<n0+1;i++)
                for(j=0;j<n0+1;j++){  	
                    UV[i][j][0]=i*division;
     	            UV[i][j][1]=j*division;     
                }
	
            for(i=0;i<4;i++)
                for(j=0;j<4;j++){ 
                    PX[i][j]=P[i][j][0];
                    PY[i][j]=P[i][j][1];
                    PZ[i][j]=P[i][j][2];
                    P4[i][j]=P[i][j][3];  
                }	
 
            //
            for(i=0;i<n0+1;i++)
                for(j=0;j<n0+1;j++){
                    UU[0][0]=1.f;
                    UU[0][1]=UV[i][j][0];
                    UU[0][2]=UV[i][j][0]*UV[i][j][0];
                    UU[0][3]=UV[i][j][0]*UV[i][j][0]*UV[i][j][0];
                    VV[0][0]=1.f;
                    VV[1][0]=UV[i][j][1];
                    VV[2][0]=UV[i][j][1]*UV[i][j][1];
                    VV[3][0]=UV[i][j][1]*UV[i][j][1]*UV[i][j][1];
                    //
                    matrixm g0=new matrixm(1,4,4,UU,M1);
                    matrixm g1=new matrixm(1,4,4,g0.CC,PX);
                    matrixm g2=new matrixm(1,4,4,g1.CC,M2);
                    matrixm g3=new matrixm(1,4,1,g2.CC,VV);
                    SurfaceXYZ[i][j][0]=g3.CC[0][0];
                    //
                    matrixm g4=new matrixm(1,4,4,UU,M1);
                    matrixm g5=new matrixm(1,4,4,g4.CC,PY);
                    matrixm g6=new matrixm(1,4,4,g5.CC,M2);
                    matrixm g7=new matrixm(1,4,1,g6.CC,VV);
                    SurfaceXYZ[i][j][1]=g7.CC[0][0];
                    //
                    matrixm g8=new matrixm(1,4,4,UU,M1);
                    matrixm g9=new matrixm(1,4,4,g8.CC,PZ);
                    matrixm g10=new matrixm(1,4,4,g9.CC,M2);
                    matrixm g11=new matrixm(1,4,1,g10.CC,VV);
                    SurfaceXYZ[i][j][2]=g11.CC[0][0];
                    //
                    matrixm g12=new matrixm(1,4,4,UU,M1);
                    matrixm g13=new matrixm(1,4,4,g12.CC,P4);
                    matrixm g14=new matrixm(1,4,4,g13.CC,M2);
                    matrixm g15=new matrixm(1,4,1,g14.CC,VV);
                    SurfaceXYZ[i][j][3]=g15.CC[0][0];   
                    //

                    SurfaceXYZ[i][j][0]=SurfaceXYZ[i][j][0]/SurfaceXYZ[i][j][3];
                    SurfaceXYZ[i][j][1]=SurfaceXYZ[i][j][1]/SurfaceXYZ[i][j][3];
                    SurfaceXYZ[i][j][2]=SurfaceXYZ[i][j][2]/SurfaceXYZ[i][j][3];
                }

            QuadArray BeziersurfacecontrolPointsNet = new QuadArray(n0*n0*4, GeometryArray.COORDINATES| GeometryArray.NORMALS);
            int c=0;//
            for(i=0;i<n0;i++) {
                for(j=0;j<n0;j++){
                    //
                    Point3f A=new Point3f(SurfaceXYZ[i][j][0],SurfaceXYZ[i][j][1], SurfaceXYZ[i][j][2]);
                    Point3f B=new Point3f(SurfaceXYZ[i][j+1][0],SurfaceXYZ[i][j+1][1],SurfaceXYZ[i][j+1][2]);
                    Point3f C=new Point3f(SurfaceXYZ[i+1][j+1][0],SurfaceXYZ[i+1][j+1][1],SurfaceXYZ[i+1][j+1][2]);
                    Point3f D=new Point3f(SurfaceXYZ[i+1][j][0],SurfaceXYZ[i+1][j][1],SurfaceXYZ[i+1][j][2]);
                    //
                    Vector3f a = new Vector3f(A.x - B.x, A.y - B.y, A.z - B.z);
                    Vector3f b = new Vector3f(C.x - B.x, C.y - B.y, C.z - B.z);
                    Vector3f n = new Vector3f();
                    n.cross(b, a);
                    n.normalize();
                    //
                    BeziersurfacecontrolPointsNet.setCoordinate(c, A);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+1, B);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+2, C);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+3, D);
                    //
                    BeziersurfacecontrolPointsNet.setNormal(c, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+1, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+2, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+3, n);
                    c=c+4;
                }
            }
            this.addGeometry(BeziersurfacecontrolPointsNet);
            this.setAppearance(app);
        }
    }
    //
    class  BezierSurfaceControlPoints extends Shape3D{   
        public BezierSurfaceControlPoints(float[][][] P,Appearance app){
	        int i,j,k;
            QuadArray BeziersurfacecontrolPointsNet = new QuadArray(3*3*4,GeometryArray.COORDINATES|GeometryArray.NORMALS);
            int c=0;	
            for(i=0;i<3;i++){      
                for(j=0;j<3;j++){
	                Point3f A=new Point3f(P[i][j][0],P[i][j][1],P[i][j][2]);
                    Point3f B=new Point3f(P[i][j+1][0],P[i][j+1][1],P[i][j+1][2]);
                    Point3f C=new Point3f(P[i+1][j+1][0],P[i+1][j+1][1],P[i+1][j+1][2]);
                    Point3f D=new Point3f(P[i+1][j][0],P[i+1][j][1],P[i+1][j][2]);
    
                    Vector3f a = new Vector3f(A.x - B.x, A.y - B.y, A.z - B.z);
                    Vector3f b = new Vector3f(C.x - B.x, C.y - B.y, C.z - B.z);
                    Vector3f n = new Vector3f();
                    n.cross(b, a);
                    n.normalize();
    
                    BeziersurfacecontrolPointsNet.setCoordinate(c, A);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+1, B);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+2, C);
                    BeziersurfacecontrolPointsNet.setCoordinate(c+3, D);
    
                    BeziersurfacecontrolPointsNet.setNormal(c, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+1, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+2, n);
                    BeziersurfacecontrolPointsNet.setNormal(c+3, n);
                    c=c+4;
                }
            }
            this.addGeometry(BeziersurfacecontrolPointsNet);
            this.setAppearance(app);
        }
    }

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





