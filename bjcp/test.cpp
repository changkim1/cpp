#include <iostream>

using namespace std;

int arry[1000][1000];

int main(){

   int col,row;
   cin >>col >>row;
   //7,6
   int H;
   cin >>H;
   //11

   // start ver

   int count = 0;
   
   int start[2] = {1,0};
   int swit = 1;
   if(col * row <H)
   {
      cout<<"0"<<endl;
      return 0;
   }else{

      while(1)
      {
         //
         for(int i=0;i<row;i++)
         {
            start[1] += swit;
            count++;

            if(count == H) {
               cout<<start[0]<<" "<<start[1]<<endl;
               return 0;
            }

         }
      
         col--;

         for(int i=0;i<col;i++)
         {
            start[0] += swit;
            count++;
            if(count == H) {
               cout<<start[0]<<" "<<start[1]<<endl;
               return 0;
            }
         }

         row--;
         swit *= -1;

      }

   }  
  
   return 0;
}