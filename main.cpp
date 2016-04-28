#include "functions.h"

using namespace std;


int main()
{
 system ("clear");
 char po;
 vector <comp> ob;
 char *namefile = new char[100];
 
 cout<< "\n" <<"Укажите имя файла: ";
 cin>>namefile;
 ifstream fin(namefile); 
 if (fin)
        {
         fin.close();
         cout<<"\n" <<"Такой файл уже существует" << "\n";
        }
  for (;;)
         {
          po = menu();
          switch (po)
                   {
                    case 1:system("clear");read(ob,namefile);
                    break;
                    
                    case 2:system("clear");add(ob);
                    break;
                    
                    case 3: system("clear"); sortirovka(ob); see(ob); 
                    break;
                    
                    case 4:system("clear");redact(ob) ;
                    break;
                    
                    case 5:system("clear");destaff(ob);
                    break;
                    
                    case 6:system("clear"); delcomp(ob);
                    break;
                    
                    case 7:system("clear"); search(ob);
                    break;
                    
                    case 8:system ("clear");  get_power_staff(ob);
                    break;
                    
                    case 9:system ("clear"); write(ob,namefile);
                    break;
                      
                    case 10: return 1;
                  
                   
                   
                   
                   
                   } 
         }
  
return 0;


}
