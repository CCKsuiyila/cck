#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
struct SPoint{
	int x;
	int y;
};
struct SEdge{
	int from;
	int to;
};

int main(){
	double length(int num_point,SPoint* points,int num_edge,SEdge* edges);
	int check_st(int num_point,int num_edge,SEdge* edges);
	int num_point;
	SPoint *points;
	int num_edge;
	SEdge *edges;
	fscanf(stdin,"%d",&num_point);
	points=(SPoint*)malloc(sizeof(SPoint)*num_point);
	for (int i=0;i<num_point;i++){
		int x,y;
		fscanf(stdin,"%d %d",&x,&y);
		points[i].x=x;
		points[i].y=y;
	}
	fscanf(stdin,"%d",&num_edge);
	edges=(SEdge*)malloc(sizeof(SEdge)*num_edge);
	for (int i=0;i<num_edge;i++){
		int from,to;
		fscanf(stdin,"%d %d",&from,&to);
		edges[i].from=from;
		edges[i].to=to;
	}
	int is_spanning_tree=check_st(num_point,num_edge,edges);
	if (is_spanning_tree){
		double path_length=length(num_point,points,num_edge,edges);
		fprintf(stdout,"%.4lf\n",path_length);
	}else{
		fprintf(stdout,"not a spanning tree\n");
	}
}

int check_st(int num_point,int num_edge,SEdge* edges){
	int count=0;
	int *root=(int*)malloc(sizeof(int)*num_point);
	for (int i=0;i<num_point;i++) root[i]=i;
	for (int i=0;i<num_edge;i++){
		int from=edges[i].from;
		int to = edges[i].to;
		int sum=root[from]<root[to]?root[from]:root[to];
		for (int j=1;j<num_point;j++){
			if (root[j]==from||root[j]==to) root[j]=sum;
		}
	}
	for (int i=0;i<num_point;i++){
		if (root[i]){
			fprintf(stdout,"vertex %d is not connected to vertex 0\n");
			count++;
		}
	}
	return !count;
}

double length(int num_point,SPoint* points,int num_edge,SEdge* edges){
	double result=0.0;
	for (int i=0;i<num_edge;i++){
		int from=edges[i].from;
		int to=edges[i].to;
		int dx=points[from].x-points[to].x;
		int dy=points[from].y-points[to].y;
		double edge_len=sqrt(dx*dx+dy*dy);
		result+=edge_len;
	}
	return result;
}