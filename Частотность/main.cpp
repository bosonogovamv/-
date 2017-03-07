#include <iostream>
#include <fstream>
#include <windows.h>
#include <cctype>

using namespace std;

class RussianAlphabet
{
    private:
        double chast[33];
        char symbol[33] = {'а', 'б', 'в', 'г', 'д', 'е', 'Є', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', '€'};;

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
              f_out << "Ѕуква '" << symbol[i] << "' встречаетс€ " << kolvo[i] << "раз(а). „астотность: " << chast[i] << endl;
          }
          f_out << "ќбщее количество букв в тексте: " << schet;
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
	    cout << "ќшибка при открытии файла!";
	    return 1;
	}

	char text, str; //str - считываетс€ из файла
    while(f_in)
    {
        f_in >> str;
        if (isalpha(str))
        {
            schet++;
            str = (char) tolower(str); //перевод символов в нижний регистр

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
