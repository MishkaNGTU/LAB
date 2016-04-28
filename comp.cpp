#include "functions.h"
using namespace std;


comp::comp()
{
 staff = 0;
 power = 0;
 unit =0;
 name = new char[100];
 ip = new char[16];
}

comp::comp(int pow,int un, int st, char *nam, char *IP ) 
{
   
   power = pow;
   unit = un;
   staff = st;
   name = new char[100];
   strcpy (name,nam);
   ip = new char[16];
   strcpy (ip,IP);
   
}

int comp::zamena (int pow, int un, char *nam, char *IP)
{
   power = pow;
   unit = un;
   name = new char[100];
   strcpy (name,nam);
   ip = new char[16];
   strcpy (ip,IP);
}   

int comp::show() 
{
   std::cout << "\n Number staff's:" << staff;
   std::cout << "\n Name: " << name ;
   std::cout << "\n IP: " << ip;
   std::cout << "\n Power: " << power;
   std::cout << "\n Unit: " << unit ;

}


int comp::operator > (comp ob2)
{return (staff > ob2.staff);}


int comp::operator < (comp ob2)
{return (staff < ob2.staff);}


comp& comp::operator = (comp & ob)
{
   staff=ob.staff;
   power=ob.power;
   unit=ob.unit;
   name = new char[100];
   strcpy (name,ob.name);
   ip = new char[16];
   strcpy (ip,ob.ip);
   return *this;

}



int comp::get_unit()
{
 return unit;
}


int comp::get_power()
{
 return power;
}

int comp::get_staff()
{
 return staff;
}


char* comp::get_name()
{
 return name;
}

char* comp::get_ip()
{
 return ip;
}


int menu()// МЕНЮ 
{
     int c;
     
     cout << "\n\n";
     cout << "1. Считать базу" << "\n";
     cout << "2. Добавить компьютер в шкаф" << "\n";
     cout << "3. Вывести информацию" << "\n";
     cout << "4. Редактирование" << "\n";
     cout << "5. Удалить шкаф" << "\n";
     cout << "6. Удалить компьютер" << "\n";
     cout << "7. Поиск" << "\n";
     cout << "8. Показать мощность шкафа" << "\n";
     cout << "9. Сохранить информацию" << "\n";
     cout << "10. Выход" << "\n";
     
     do {
     
     cout << "\n" << "Введите нужный номер: ";
     cin >> c;
     
     } while (c<1||c>10);
       return c;
   

}




int add (vector<comp> &ob) //ДОБАВЛЕНИЕ КОМПЬЮТЕРА
{
   int pow, un, st;
   char *nam = new char [100], *IP = new char [100];
   
  
   
   cout <<"\n" <<"Введите номер шкафа:" << "\n";
   cin >> st;
   
   cout << "Введите имя компьютера:" << "\n";
   cin >> nam;
   
   cout << "Введите мощность компьютера:" << "\n";    
   cin >> pow;
   
   cout << "Введите размеры компьютера(в юнитах):" << "\n";
   cin >> un;
   
   if (ogran_unit(ob,st,un)==1){cout << "\n" << "Компьютер с такими размерами не влазит в шкаф" << "\n" ; return 1;}
   
   cout << "Введите IP адрес" << "\n";
   cin >> IP;
   
   ob.push_back (comp(pow,un,st, nam, IP ));
   
   return 1;

}

int ogran_unit(vector<comp> &ob, int s, int u)
{
 int i,summ=0;
 
 for (i=0;i<ob.size();i++)
           {
            if (s==ob[i].get_staff()) summ=summ+ob[i].get_unit();
           }
 if ((summ+u)>40) return 1;
 return 0;


}

int see (vector<comp> &ob) // ВЫВОД
{
  int i;
  
  if (ob.empty()==0) {    
       for(i=0;i<ob.size();i++)
          
           {
            cout<<"\n\n";
            ob[i].show();
           };
           
           std::cout<<"\n";
  }


}


int sortirovka(vector<comp> &ob)
{

 comp cop;
 int i, flag;
 
if (ob.empty()==0){ 
 while (1) 
 {

 flag=0;

 for (i=0;i<ob.size()-1;i++)
   { 
     if (ob[i]>ob[i+1])
           {
            cop=ob[i+1];
            ob[i+1]=ob[i];
            ob[i]=cop;
            flag=1;
           }
   }        
    if (flag==0) break;
  }
  } if(ob.empty()==1) cout <<"\n"<< "Нет элементов в базе!";  
   return 1;       
}


int redact(vector<comp> &ob)
{
 int pow, un, st, shk,flag,i;
 char *nam = new char [100], *IP = new char [100], *cmp = new char[100]; 
 
 cout <<"\n" <<"Введите номер шкафа: ";
 cin >> shk;
 
 cout <<"\n" << "Введите название компьютера: ";         
                       cin >> cmp;
 
        for (i=0;i<ob.size();i++)
          {
             if ((ob[i].get_staff()==shk) && ((strcmp(cmp,ob[i].get_name())==0) ))
                      {
                                       
                                        cout <<"\n" <<"Введите новое название компьютера: ";
                                        cin >> nam;
                                           
                                        cout <<"\n" << "Введите новую мощность компьютера: ";    
                                        cin >> pow;
    
                                        cout <<"\n" << "Введите новые размеры компьютера: ";
                                        cin >> un;
   
                                        cout <<"\n"<< "Введите новый IP адрес: ";
                                        cin >> IP;
   
                                        ob[i].zamena( pow,un, nam, IP);
                                        flag=1;
                                        break;  
                                       
                      }  
          }
         if (flag==0) cout << "\n" << "!!!Нет такого компьютера!!!";
return 1;          
}

int destaff (vector<comp> &ob)// Удалить шкаф
{
  int shk,i,index,flag=0;
  cout << "Введите номер шкафа, кторый хотите удалить: ";
  cin >> shk;
  
  
  
     
      for (i=0;i<ob.size();i++)
                 {
                  if (shk==ob[i].get_staff()){ index=i;
                  break; }
                 }
      while(1)
          {
           if (shk==ob[index].get_staff()) {ob.erase(ob.begin()+index);flag=1; } 
           else break;
           
           
           if (index>=ob.size()) break;  
          }   
if (flag==1) cout << "\n" << "Шкаф удален!";
else cout << "\n" << "Нет такого шкафа!";
return 1;
}



int delcomp (vector<comp> &ob) // Удалить компьютер
{
     int shk, i,flag;
     char  *cmp = new char[100];  
    
     cout << "\n"<<"Введите номер шкафа, в котором хотите удалить компьютер: ";
     cin >> shk;

     cout << "\n" <<"Введите название компьютера: ";
     cin >> cmp;
     
              for (i=0;i<ob.size();i++)
                              {
                                flag=0;
                                if ((shk==ob[i].get_staff())&&(strcmp(cmp,ob[i].get_name())==0))
                                                              {
                                                               ob.erase(ob.begin()+i);
                                                               flag=1;
                                                               cout << "\n" << "Компьютер удален"; 
                                                               break;
                                                              }
                                                             
                              }
if (flag==0) {  cout << "\n" << "!!!Нет такого компьютера!!!"; }                                                           
return 1;              
}



