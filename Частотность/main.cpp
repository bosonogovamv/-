#include <iostream>
#include <fstream>
#include <windows.h>
#include <cctype>

using namespace std;

class RussianAlphabet
{
    private:
        double chast[33];
        char symbol[33] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};;

    public:
        int kolvo[33];

    char get_symb(int i)
      {
          return symbol[i];
      }

    double get_chast(int schet)
      {
          for (int i = 0; i < 33; i++)
              chast[i] = (double) kolvo[i]/schet;
      }

    void show(int schet)
      {
          ofstream f_out("out.txt");
          for (int i = 0; i < 33; i++)
          {
              f_out << "����� '" << symbol[i] << "' ����������� " << kolvo[i] << "���(�). �����������: " << chast[i] << endl;
          }
          f_out << "����� ���������� ���� � ������: " << schet;
          f_out.close();
      }

      void start_kolvo()
      {
          for (int i = 0; i < 33; i++)
          {
              kolvo[i] = 0;
          }
      }
};


int main()
{
    setlocale(LC_ALL,"rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	ifstream f_in("in.txt");

	RussianAlphabet alphabet;
	alphabet.start_kolvo();

	int schet = 0;

	if (!f_in)
	{
	    cout << "������ ��� �������� �����!";
	    return 1;
	}

	char text, str; //str - ����������� �� �����
    while(f_in)
    {
        f_in >> str;
        if (isalpha(str))
        {
            schet++;
            str = (char) tolower(str); //������� �������� � ������ �������

            for (int i = 0; i < 33; i++)
            {
                if (alphabet.get_symb(i) == str)
                {
                    alphabet.kolvo[i]++;
                    break;
                }
            }
        }
    }

    f_in.close();
    alphabet.get_chast(schet);
    alphabet.show(schet);

    return 0;
}
