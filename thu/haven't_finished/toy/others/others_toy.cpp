 //玩具(Toy)，类似魔板问题，但只需输出步骤数即可
 //Time:28Ms  Memory:13376MB (No.10)
 #include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 #define MAX 40321
 int Map[MAX];    //状态图
 int fac[8] = { 1,1,2,6,24,120,720,5040};
 struct Board{
     int fa;        //记录上一状态
     int val;    //Hash值
     char str[9];
     void Contor();
 }m[2*MAX],ts;
 void Board::Contor()
 {
     int num = 0;
     for (int i = 0; i < 8; i++)
     {
         int tmp = 0;
         for (int j = i + 1; j < 8; j++)
         {
             if (this->str[j] < this->str[i]) tmp++;
         }
         num += tmp*fac[7 - i];
     }
     this->val = num;
 }
 void Init(char s[9])
 {
     int rear = 0;
     int tail = 1;
     strcpy(m[0].str, s);
     m[0].Contor();
     while (rear < tail) {
         if (Map[m[rear].val])
         {
             rear++;
             continue;
         }
         Map[m[rear].val] = Map[m[m[rear].fa].val] + 1;
         /*由于是反向搜索，因此将逆向操作即可*/
         // 交换行
         for (int i = 0; i < 8; i++)
             m[tail].str[(i + 4) % 8] = m[rear].str[i];
         m[tail].Contor();
         if (!Map[m[tail].val]) {
             m[tail].fa = rear;
             tail++;
         }
         // 循环左移
         for (int i = 0; i < 4; i++)
             m[tail].str[(i + 3) % 4] = m[rear].str[i];
         for (int i = 4; i < 8; i++)
             m[tail].str[(i + 3) % 4 + 4] = m[rear].str[i];
         m[tail].Contor();
         if (!Map[m[tail].val]) {
             m[tail].fa = rear;
             tail++;
         }
         // 中心逆旋转
         strcpy(m[tail].str, m[rear].str);
         m[tail].str[5] = m[rear].str[1]; m[tail].str[1] = m[rear].str[2];
         m[tail].str[2] = m[rear].str[6]; m[tail].str[6] = m[rear].str[5];
         m[tail].Contor();
         if (!Map[m[tail].val]) {
             m[tail].fa = rear;
             tail++;
         }
         rear++;
     }
 }
 int main()
 {
     /*预处理*/
     Init("12348765");
     int T;
     scanf("%d", &T);
     while (T--)
     {
         int tmp;
         for (int i = 0; i < 4; i++)
        {
             scanf("%d", &tmp);
             ts.str[i] = tmp + '0';
         }
         for (int i = 4; i < 8; i++)
         {
            scanf("%d", &tmp);
             ts.str[(8 - i) + 3] = tmp + '0';
         }
         ts.Contor();
         printf("%d\n", Map[ts.val] - 1);
     }
     return 0;
 }
