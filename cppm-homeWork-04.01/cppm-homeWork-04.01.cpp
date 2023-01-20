
#include <iostream>
#include <fstream>
#include <string>


class Adresses
{
public:

	std::string read_to_file(int N, std::ifstream &fin)
	{

		fin >> Adresses::city;
		fin >> Adresses::street;
		fin >> Adresses::num_house;
		fin >> Adresses::num_kv;

		std::string num_house1 = std::to_string(num_house);
		std::string num_kv1 = std::to_string(num_kv);

		std::string adres = city + ", " + street + ", " + num_house1 + ", " + num_kv1;

		return adres;
			


	}
	
	void write_to_file(int N, std::ofstream &fout, std::string arr)
	{

		for (int j = N-1; j >= 0; j--) {

			fout << arr[j] << std::endl;
		}

		
	}

	int setter(int N) {

		if (N > 0) {
			this->N = N;
			return N;
			
		}
		else {
			std::cout << "Размерность некоректна!";
			return -1;
			
		}

	}
	

private:

	int N = 0;
	std::string city = "Неизвестно";
	std::string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;

};


int main()
{
	Adresses adres;

	int N;
	
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	if (fin.is_open() && fout.is_open()) {

		fin >> N;
		N = adres.setter(N);

		std::string* arr = new std::string[N]();
		std::string adress;

		fout << N << std::endl;

		for (int i = 0; i < N; i++)
		{
			adress = adres.read_to_file(N, fin);
			arr[i] = adress;
			
		}

		//adres.write_to_file(N, fout, *arr);

		for (int j = N-1; j >= 0; j--) { fout << arr[j] << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;
    
}
 
