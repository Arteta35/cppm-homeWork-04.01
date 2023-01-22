
#include <iostream>
#include <fstream>
#include <string>


class Adresses
{
public:

	void in_city(std::string city) {
		this->city = city;
	}

	void in_street(std::string street) {
		this->street = street;
	}

	void in_num_house (int num_house) {
		this->num_house = num_house;
	}

	void in_num_kv(int num_kv) {
		this->num_kv = num_kv;
	}

	std::string get_output(std::string city, std::string street, int num_house, int num_kv) {

		return city + ", " + street + ", " + std::to_string(num_house) + ", " + std::to_string(num_kv);

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
	std::string city = "Неизвестно";
	std::string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;
	
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
			fin >> city;
			adres.in_city(city);
			fin >> street;
			adres.in_street(street);
			fin >> num_house;
			adres.in_num_house(num_house);
			fin >> num_kv;
			adres.in_num_kv(num_kv);

			arr[i] = adres.get_output(city, street, num_house, num_kv);
			
		}

		//adres.write_to_file(N, fout, *arr);

		for (int j = N-1; j >= 0; j--) { fout << arr[j] << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;
    
}
 
