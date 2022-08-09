#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

class adress
{
private:

    std::string city, strt;
    int bldg, appt;

public:

    adress(std::string city, std::string strt, int bldg, int appt)
    {
        this->city = city;
        this->strt = strt;
        this->bldg = bldg;
        this->appt = appt;
    }
    adress() {}


    std::string make_string()
    {
        std::string dot = ", ";
        return this->city + dot + this->strt + dot + std::to_string(this->bldg) + dot + std::to_string(this->appt);
    }

    std::string get_city()
    {
        return this->city;
    }

};

void sort_adr(adress** adr_arr, int N)
{
    int changes = 1;
    adress* temp = nullptr;
    while (changes != 0) {
        changes = 0;
        for (int i = 0; i < N - 1; i++) {
            if (adr_arr[i]->get_city() > adr_arr[i + 1]->get_city())
            {
                temp = adr_arr[i];
                adr_arr[i] = adr_arr[i + 1];
                adr_arr[i + 1] = temp;
                changes++;
            }
        }
    } 
}


int main()
{
    const int format = 4;
    int N = 0;
    int bldg = 0, appt = 0;
    std::string city, strt;

    std::ifstream file_read("in.txt");
    if (!file_read.is_open())
    {
        std::cout << "Can't open input file!" << std::endl;
        return 1;
    }
    std::cout << "Input file is open" << std::endl;
    file_read >> N;
    adress** adr_arr = new adress*[N]();
    //std::string* city_arr = new std::string[N]();
    for (int i = 0; i < N; i++)
    {
        file_read >> city;
        file_read >> strt;
        file_read >> bldg;
        file_read >> appt;
        adr_arr[i] = new adress(city, strt, bldg, appt);
        //city_arr[i] = adr.get_city();
        //adr_arr[i] = adr.make_string();
    }

    sort_adr(adr_arr, N);

    file_read.close();
    std::ofstream file_write("out.txt");
    if (!file_write.is_open())
    {
        std::cout << "Can't open output file!" << std::endl;
        return 1;
    }
    std::cout << "Output file is open" << std::endl;
    file_write << N << std::endl;

    for (int i = 0; i < N; i++)
    {
        
        file_write << adr_arr[i]->make_string() << std::endl;
    }


    //delete[] city_arr;

    file_write.close();

    delete[] adr_arr;
    std::cout << "Done!" << std::endl;

}
