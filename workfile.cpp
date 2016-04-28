#include "functions.h"
using namespace std;

int zapis_f(std::ostream & stream,const comp &ob)
{
    stream<<ob.staff<<"\n";
    stream<<ob.name<<"\n"; 
    stream<<ob.power<<"\n";
    stream<<ob.unit<<"\n"; 
    stream<<ob.ip;
    return 1;
}
 
int write(std::vector<comp> &ob, char *namefile) // Запись в файл
{
  int i;
  std::ofstream fox(namefile, ios::out | ios::binary);
  if(ob.size()>0)
            {
              zapis_f(fox,ob[0]);
              for (i=1;i<ob.size();i++)
               {
                fox<<"\n";
                zapis_f(fox,ob[i]);
               }   
            }      
  fox.close();     
  cout <<"\n" << "Данные сохранены в файле: "<< namefile <<"\n";
}


int chtenie_f (std::istream & stream,comp &ob )
{
    stream>>ob.staff;
    stream>>ob.name; 
    stream>>ob.power;
    stream>>ob.unit; 
    stream>>ob.ip;
    return 1;
}
 
 

int read(std::vector<comp> &ob, char *namefile) //чтение из файла
{
 std::ifstream fin(namefile,ios::in|ios::binary );
 int i=0;   
 ob.clear();
 if(!fin)   
        {
         return 0;
        }
  ob.push_back(comp());
  while (1)
          {
           if (fin.eof()==1) break;
           ob.push_back(comp());   
           chtenie_f(fin, ob[i]);
           i++;
          }
          ob.pop_back();
  fin.close();
  cout << "\n"<<"Данные успешно считаны! "<<"\n";
  return 1;
 
}

