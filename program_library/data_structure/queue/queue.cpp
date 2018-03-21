//这次相比原来改进了一下思路,采用了类似广度优先搜索的方法,但还是和原来一样的分数,60    下面的好多超时
//然后想办法加速,看到一个别人的代码,学习了他的邻接表,把那些quicksort,binary_search去了  
//然后就70分了    下面超时少了   变成了错误
//暂时先到这里   有空再来

#include<iostream>
#include<cstdio>
using namespace std;

class QUEUE{
	public:
		QUEUE(int length);//构造函数
		int current_size;//队列总元素个数
		bool enqueue(int value);//入队
		int dequeue();//出队
	private:
		int max_size;//队列最大长队
		int head;//队头下标
		int tail;//队尾下标
		int * array;//储存元素的数组
};

QUEUE::QUEUE(int length){
	current_size = 0;
	max_size = length;
	head = 0;
	tail = 0;
	array = new int[length+10];
}
bool QUEUE::enqueue(int value){
	if(current_size <= max_size){//此处应为<=而不是<
		array[head] = value;
		if((max_size -1) == head){
			head = 0;
		}else{
			++head;
		}
		++current_size;
		return true;
	}
	return false;
}
int QUEUE::dequeue(){
	if(current_size > 0){
		int temp = array[tail];
		if((max_size -1) == tail){
			tail = 0;
		}else{
			++tail;
		}
		--current_size;
		return temp;
	}
}



//看了人家的代码,感觉写个邻接表能提速很多,那就写个吧
//Adjacency_list

class Node{
	public:
		Node();
		Node* succ;
		int city_name;
};
Node::Node(){
	succ = NULL;
	city_name = 0;
}

Node* array = new Node[3000010];//改了这里60变为70(2)
int array_index = 0;

class City{
	public:
		City();
		int number;
		Node* the_head;
		Node* current;
		void insertbehind(int value);
};

City::City(){
	number = 0;
	the_head = &(array[array_index]);
	++array_index;
	current = the_head;
}

void City::insertbehind(int value){
	Node *temp = &(array[array_index]);
	++array_index;
	temp->city_name = value;
	current->succ = temp;
	current = temp;
}

int main(){
	//输入
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	City* city = new City[2000010];//改了这里60变为70(1)
	int *find_origin=new int[2000010];
	for(int i = 0; i < 2000010; ++i){
		find_origin[i] = 0;
	}
	for (int i = 0; i < m; ++i){
		int x, y;   
		fscanf(stdin, "%d %d", &x, &y);
		find_origin[y]=y;//
		city[x].insertbehind(y);
	}
	//找出所有没有被指向的点,也就是可以作为起点的点(这是直接复制过来的,略作修改,就是不放入那个origin数组里面了,直接入队)
	QUEUE queue(2000010);
	for(int i=1 ;i<=n;++i){
		if(i!=find_origin[i]){
			queue.enqueue(i);
		}
	}
	//开始拓扑排序,也类似于广度优先搜索
	int count = 0;
	while(queue.current_size > 0){
		++count;
		for(int i = 0, j = queue.current_size; i < j; ++i){
			int from = queue.dequeue();
			Node* a = city[from].the_head;
			for(; a->succ != NULL;){//
				a = a->succ;
				queue.enqueue(a->city_name);
			}
		}
	}
	fprintf(stdout,"%d", count);
	return 0;
}

