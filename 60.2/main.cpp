#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int ostatnia;

int przedostatnia;

int ile_dzielnikow= 0;

int podzielone;


class rozkladanie{
	public:
		vector <int> liczby;
		vector <int> wynik;
		vector <int> pomocniczy;
		


		
		
		int wczytaj_z_pliku(const char *nazwa)
		{
			int wprowadzany;
			fstream plik;
                plik.open(nazwa,ios::in);  
				{
                  	for(int i=0; i<=199;i++ )
                  	{ 

		                plik>>wprowadzany;
		                liczby.push_back(wprowadzany);
				
	                }
	            }
                   plik.close();  
                   
		};
		
		
		
		int rozloz(){
				
		 for (vector<int>::iterator it = liczby.begin(); it != liczby.end(); ++it)
        {
        	int liczba = *it;
        	for (int i=1; i<=liczba; i++)
			{
			podzielone = liczba / i;
			if ( liczba % i == 0)
					 { 
					pomocniczy.push_back(podzielone);
					 ile_dzielnikow++;

					

						}
					 }
					 
					 
			  if(ile_dzielnikow==18){
			  	cout<<liczba<<"  ";
			 	 for (vector<int>::iterator it = pomocniczy.end()-1; it != pomocniczy.begin();  it--)
        			{
        				int dzielnik = *it;
						cout<<dzielnik<< "  ";
					}
					cout<<endl;
					}
					pomocniczy.clear();
					ile_dzielnikow=0;
				}
		

  		  };
        
};


	int main(int argc, char** argv) {
	
	rozkladanie r;
	
	r.wczytaj_z_pliku("b.txt");
	r.rozloz();
	return 0;
}
