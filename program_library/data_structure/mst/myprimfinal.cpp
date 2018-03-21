#include<cstdio>
#include<cstdlib>
using namespace std;
struct SPoint{
	int x;
	int y;
	int number;
	int from;
};
struct SEdge{
	int from;
	int to;
};
//long long int count=0;
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
	//fprintf(stdout,"%lld\n",count);
	return 0;
}


int prim(int n,SPoint* data,SEdge* result){
	int Max=2*10000*10000+1;
	SPoint *tree=(SPoint*)malloc(sizeof(SPoint)*n);
	tree[0].x=data[0].x;
	tree[0].y=data[0].y;
	tree[0].number=0;
	data[0].x=Max;
	data[0].y=Max;
	for(int i=0;i<n;i++){
		data[i].number=Max;
		data[i].from=0;
	}
	for(int i=1;i<n;i++){
		int nd=Max;
		int length=Max;
		for(int k=1;k<n;k++){
			int dx=data[k].x;
			int dy=data[k].y;
			int tx=tree[i-1].x;
			int ty=tree[i-1].y;
			if(dx<20000&&(dx-tx)*(dx-tx)+(dy-ty)*(dy-ty)<data[k].number){
				data[k].number=(dx-tx)*(dx-tx)+(dy-ty)*(dy-ty);
				data[k].from=tree[i-1].number;
			}
			if(dx<20000&&data[k].number<length){
				length=data[k].number;
				tree[i].x=data[k].x;
				tree[i].y=data[k].y;
				tree[i].number=k;
				result[i-1].from=data[k].from;
				result[i-1].to=tree[i].number;
				nd=k;
		    }
		}
		//count++;
		data[nd].x=Max;
		data[nd].y=Max;
	}
}
	
	
