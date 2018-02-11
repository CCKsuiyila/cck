#include<cstdio>
#include<cstdlib>
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
	int prim(int,SPoint*,SEdge*);
	int n;
	fscanf(stdin,"%d",&n);
	SPoint *data=(SPoint*)malloc(sizeof(SPoint)*n);
	SEdge *result=(SEdge*)malloc(sizeof(SEdge)*(n-1));
	for (int i=0;i<n;i++){
		int x,y;
		fscanf(stdin,"%d %d",&x,&y);
		data[i].x=x;
		data[i].y=y;
	}
	prim(n,data,result);
	fprintf(stdout,"%d\n",n-1);
	for (int i=0;i<n-1;i++){
		fprintf(stdout,"%d %d\n",result[i].from,result[i].to);
	}
	return 0;
}

int prim(int n,SPoint* data,SEdge* result){
	int* dist_sqr=(int*)malloc(sizeof(int)*n);
	int* source=(int*)malloc(sizeof(int)*n);
	int inf=2*10000*10000+1;
	for(int i=0;i<n;i++) dist_sqr[i]=inf;
	int from=0;
	dist_sqr[from]=0;
	int to=0;
	int count=1;
	while(count<n){
		int min_dist_sqr=inf;
		for (int i=1;i<n;i++) {
			if (dist_sqr[i]){
				int dx=data[from].x-data[i].x;
				int dy=data[from].y-data[i].y;
				int cur_dist_sqr=dx*dx+dy*dy;
				if (cur_dist_sqr<dist_sqr[i]) {
					dist_sqr[i]=cur_dist_sqr;
					source[i]=from;
				}
				if (dist_sqr[i]<min_dist_sqr){
					min_dist_sqr=dist_sqr[i];
					to=i;
				}				
			}
		}
		count++;
		int r_index=count-2;
		result[r_index].from=source[to];
		result[r_index].to=to;
		from=to;
		dist_sqr[from]=0;
	}
	return 0;
}