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

    std::string* make_string()
    {
        std::string* arr = new std::string[4]();

        arr[0] = this->city;
        arr[1] = this->strt;
        arr[2] = std::to_string(this->bldg);
        arr[3] = std::to_string(this->appt);
        return arr;
    }

};

void sort_2d_arr(std::string** twod_arr, int size)
{
    const char* c[5] = { 
        twod_arr[0][0].c_str(), 
        twod_arr[1][0].c_str(),
        twod_arr[2][0].c_str(), 
        twod_arr[3][0].c_str(), 
        twod_arr[4][0].c_str()};

    bool changes = false;
    do {
        changes = false;
        for (int i = size - 1; i > 0; i--) {
            std::cout << "________________________________" << std::endl;
            std::cout << c[i] << " " << c[i - 1] << std::endl;
            std::cout << "________________________________" << std::endl;
            if (strcmp(c[i],c[i-1]) == -1 )
            {
                for (int j = 0; j < 4; j++)
                {
                    std::string temp = twod_arr[i][j];
                    twod_arr[i][j] = twod_arr[i - 1][j];
                    twod_arr[i - 1][j] = temp;
                }
                changes = true;
            }
        }
    } while (changes);
}

int open_file(std::string path)
{
    std::ifstream file_read(path);
    if (!file_read.is_open())
    {
        std::cout << "Can't open input file!" << std::endl;
        return 1;
    }
    std::cout << "File is open" << std::endl;
    return 0;
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
    std::string** adr_2d_arr = new std::string*[N]();
    for (int i = 0; i < 4; i++)
    {
        adr_2d_arr[i] = new std::string[format];
    }

    for (int i = 0; i < N; i++)
    {
        file_read >> city;
        file_read >> strt;
        file_read >> bldg;
        file_read >> appt;
        adress adr(city, strt, bldg, appt);
        adr_2d_arr[i] = adr.make_string();
    }

    
    std::cout << adr_2d_arr[0][0] << " " << adr_2d_arr[0][1] << std::endl;
    std::cout << adr_2d_arr[1][0] << " " << adr_2d_arr[1][1] << std::endl;
    std::cout << adr_2d_arr[2][0] << " " << adr_2d_arr[2][1] << std::endl;
    std::cout << adr_2d_arr[3][0] << " " << adr_2d_arr[3][1] << std::endl;
    std::cout << adr_2d_arr[4][0] << " " << adr_2d_arr[4][1] << std::endl << std::endl;

    sort_2d_arr(adr_2d_arr, N);

    std::cout << adr_2d_arr[0][0] << " " << adr_2d_arr[0][1] << std::endl;
    std::cout << adr_2d_arr[1][0] << " " << adr_2d_arr[1][1] << std::endl;
    std::cout << adr_2d_arr[2][0] << " " << adr_2d_arr[2][1] << std::endl;
    std::cout << adr_2d_arr[3][0] << " " << adr_2d_arr[3][1] << std::endl;
    std::cout << adr_2d_arr[4][0] << " " << adr_2d_arr[4][1] << std::endl;


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
        for (int j = 0; j < 4; j++)
        {
            j == 3 ? file_write << adr_2d_arr[i][j] << std::endl : file_write << adr_2d_arr[i][j] << ", ";
        }

    }
    file_write.close();
    for (int i = 0; i < format; i++)
    {
        delete[] adr_2d_arr[i];
    }
    delete[] adr_2d_arr;

    std::cout << "Done!" << std::endl;

}
