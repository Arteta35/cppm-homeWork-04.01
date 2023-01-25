
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

	std::string get_output() {

		return city + ", " + street + ", " + std::to_string(num_house) + ", " + std::to_string(num_kv);

	}

private:

	std::string city = "Неизвестно";
	std::string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;

};


int main()
{
	int N;
	std::string city = "Неизвестно";
	std::string street = "Неизвестно";
	int num_house = 0;
	int num_kv = 0;
	
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	if (fin.is_open() && fout.is_open()) {

		fin >> N;
		if (N <= 0) {

			std::cout << "Размерность некоректна!";
			return -1;
		}

		Adresses* arr = new Adresses[N]();
		std::string adress;

		fout << N << std::endl;

		for (int i = 0; i < N; i++)
		{
			fin >> city;
			arr[i].in_city(city);
			fin >> street;
			arr[i].in_street(street);
			fin >> num_house;
			arr[i].in_num_house(num_house);
			fin >> num_kv;
			arr[i].in_num_kv(num_kv);
			
		}

		for (int j = N-1; j >= 0; j--) { fout << arr[j].get_output() << std::endl; }

		delete[] arr;

	}

	fin.close();
	fout.close();

	return 0;
    
}
 
