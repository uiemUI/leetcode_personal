
#include<string>
#include<iostream>
#include"stdio.h"
int main(int argc, char const *argv[])
{
    std::string modelName{"ssd_resnet"};
    char  buffer[200], s[] = "computer", c = 'l';
   int   i = 35, j;
   float fp = 1.7320534f;
   // 格式化并打印各种数据到buffer
   j  = sprintf( buffer,    "   String:    %s\n", s ); // C4996
   j += sprintf( buffer + j, "   Character: %c\n", c ); // C4996
   j += sprintf( buffer + j, "   Integer:   %d\n", i ); // C4996
   j += sprintf( buffer + j, "   Real:      %f\n", fp );// C4996

   printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );

  char buffername[200];
   sprintf(buffername,"TRT: %s ",modelName.c_str());
   std::string modelFullName{buffername};
   std::cout <<modelFullName<<std::endl;
   std::cout<<modelFullName.size()<<std::endl; //这样格式化太傻逼了

   


    return 0;
}
