#include "functions.h"
using namespace std;

int search (vector<comp> &ob)
{
  int pow,un,st,c;
  char *name = new char[100], *IP = new char[100]; 
  char po;
  cout <<"\n" << "Введите атрибут, по которому будете искать" << "\n";
  cout <<"\n" << "1. Название компьютера";
  cout <<"\n" << "2. Мощность компьютера";
  cout <<"\n" << "3. Размеры компьютера";
  cout <<"\n" << "4. Номер шкафа";
  cout <<"\n" << "5. IP адрес";
  cout <<"\n" << "6. Выход"; 
  do {
     
     cout << "\n" << "Введите нужный номер: " << "\n";
     cin >> c;
     
     } while (c<1||c>6);
 
  
  
  
       
         po=c;
         
         switch(po)
              {
               case 1:system("clear");searchname(ob);
               break;
               
               case 2:system("clear");searchpower(ob);
               break;
               
               case 3:system("clear");searchunit(ob);
               break;
               
               case 4:system("clear");searchstaff(ob);
               break;
               
               case 5:system("clear");searchip(ob);
               break;
               
               case 6:return 1;
               break;
              }      
         

}


int searchname (vector<comp> &ob)
{
 int i,flag=0;
 char *cmp = new char[100];
 
 cout <<"\n" << "Введите название компьютера: ";
 cin >> cmp;
 
       for (i=0;i<ob.size();i++)
           {
            if (strcmp(cmp,ob[i].get_name())==0) {flag=1; cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchip (vector<comp> &ob)
{
 int i,flag=0;
 char *IP = new char[100];
 
 cout <<"\n" << "Введите IP адрес: ";
 cin >> IP;
 
       for (i=0;i<ob.size();i++)
           {
            if (strcmp(IP,ob[i].get_ip())==0) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}


int searchunit (vector<comp> &ob)
{
 int i,flag=0,un;
 
 cout <<"\n" << "Введите размеры компьютера: ";
 cin >> un;
 
       for (i=0;i<ob.size();i++)
           {
            if (un==ob[i].get_unit()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchstaff (vector<comp> &ob)
{
 int i,flag=0,st;
 
 cout <<"\n" << "Введите номер шкафа: ";
 cin >> st ;
 
       for (i=0;i<ob.size();i++)
           {
            if (st==ob[i].get_staff()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchpower (vector<comp> &ob)
{
 int i,flag=0,pow;
 
 cout <<"\n" << "Введите мощность компьютера: ";
 cin >> pow ;
 
       for (i=0;i<ob.size();i++)
           {
            if (pow==ob[i].get_power()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}


int get_power_staff (vector<comp> &ob)
{
   int i,st,summ=0,flag=0;  
  
   cout << "Введите номер шкафа, у которого хотите узнать мощность: ";
   cin >> st; 
   
   for (i=0;i<ob.size();i++)
           {
            if (st==ob[i].get_staff()) {summ=summ+ob[i].get_power();flag=1;}
            
           }
   if (flag==1) cout <<"\n" <<"Мощность "<< st << " шкафа равна: " << summ;
   else cout << "\n" <<"Нет такого шкафа";
   
   return 1;

} 
