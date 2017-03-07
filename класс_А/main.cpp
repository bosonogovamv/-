///тип полей a,b: float
///выражения: /=, +
#include <iostream>

using namespace std;

class A
{
  private:
      float a;
      float b;
  public:
      float c;

      void show()
      {
          cout << "c=" << c;
      }
      void setab(float x, float y)
      {
          a = x;
          b = y;
          a/=b;
          c = a + b;
      }
};

int main()
{
    A obj;
    float x, y;
    cout << "a=";
    cin >> x;
    cout << "b=";
    cin >> y;

    obj.setab(x, y);
    obj.show();
    return 0;
}
