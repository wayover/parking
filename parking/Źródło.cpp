#include <iostream>
#include <vector>



class parkingg
{
private:
	int wysokosc;
	int dlugosc;
	int maxx;
	//int ** parking = new int *[wysokosc];
	std::vector <int> dlugo;
	std::vector <int> zer;
	std::vector < std::vector <int> > parking;
	int czas=0;
public:
	void setwysokosc(int wysokoscc);
	void setdlugosc(int dlugoscc);
	void dodaj(int wartosc);
	void setmax(int maks);
	void ileczasu();
	void wyswietl();
	void przesunwlewo(int poziom);
	void przesunwprawo(int poziom);
	void wys();
};

void parkingg::setwysokosc(int wysokoscc)
{
	wysokosc = wysokoscc;
	


}


void parkingg::setdlugosc(int dlugoscc)
{
	dlugosc = dlugoscc;

}


void parkingg::dodaj(int wartosc)
{
	dlugo.push_back(wartosc);
}

void parkingg::wys()
{
	parking.push_back(dlugo);
	dlugo = zer;
}


void parkingg::setmax(int maks)
{
	maxx = maks;
}

void parkingg::wyswietl()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < dlugosc; j++)

		{
			std::cout << parking[i][j] << " ";
		
		}
		std::cout << std::endl;
	}
}


void parkingg::przesunwlewo(int poziom)
{
	int temp = parking[poziom][0];
	for (int i = 0; i < dlugosc-1; i++)
	{
		parking[poziom][i] = parking[poziom][i + 1];
	}
	parking[poziom][dlugosc - 1] = temp;
	czas = czas + 5;
	std::cout << "dodaje 5 lewo: " << std::endl;
}



void parkingg::przesunwprawo(int poziom)
{
	int temp = parking[poziom][dlugosc - 1];
	for (int i = dlugosc-1; i > 0; i--)
	{
		parking[poziom][i] = parking[poziom][i -1];
	}
	parking[poziom][0] = temp;
	std::cout << "dodaje 5 prawo: "<<std::endl;
	czas = czas + 5;
	std::cout<<std::endl << std::endl;
}



void parkingg::ileczasu()
{
	int wyso = 0;
	int dlug = 0;
	for (int i = 1; i < maxx + 1; i++)
	{
		

		for (int a = 0; a < wysokosc; a++)
		{
			for (int b = 0; b < dlugosc; b++)
			{
				if (parking[a][b] == i)
				{
					
					wyso = a;
					dlug = b;
					//std::cout << "dlug: " << dlug << std::endl;
					break;
					break;
				}
			}
		}

		for (int q = 0; q < wyso; q++)
		{
			std::cout << "dodaje 20" << std::endl;
			czas = czas + 20;
		}



		std::cout << "if(" << dlug << "<=" << dlugosc / 2 << ")" << std::endl;
		if (dlug <= (dlugosc / 2))
		{
			for (int z = 0; z < dlug; z++)
			{
				przesunwlewo(wyso);
			}
			std::cout << "koniec w lewo" << std::endl;
		}
		else
		{
			for (int x = dlug; x <= dlugosc + 1; x++)
			{
				przesunwprawo(wyso);
			}
			std::cout << "koniec w prawo" << std::endl;
		}

		}

	std::cout << std::endl<<"czas: "<< czas;
	}

















 

int main()
{
	parkingg p;

	int wysokosc;
	int dlugosc;
	std::cin >> wysokosc;
	std::cin >> dlugosc;

	p.setwysokosc(wysokosc);
	p.setdlugosc(dlugosc);

	int wartosc;
	int maxx = 0;

	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < dlugosc; j++)
		{

			std::cin >> wartosc;

			if (maxx < wartosc)
			{
				maxx = wartosc;
			}

			p.dodaj(wartosc);
		}
		p.wys();
	}
	p.setmax(maxx);
//	p.ileczasu();
	p.wyswietl();

	system("pause");
	return 0;
}