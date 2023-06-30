#include <iostream>
using namespace std;
double algr(int chisl, int num) {
    if (!chisl) return sqrt(num);
    else return sqrt((num - chisl) + algr(chisl - 1, num));
}
double schet(int num, int a) {
    if (!num) return sqrt(a);
    double first = sqrt(sqrt(a) + num);
    double allsum = 0;
    double sum = first;
    num--;
    while (num > 0) {
        sum += num;
        allsum = sqrt(sum);
        sum = allsum;
        num--;
    }
    return sum;
}
int main()
{
    int chislo;
    cin >> chislo;
    cout << "answer recursion : " << algr(chislo - 1, chislo) << endl;
    cout << "answer with while : " << schet(chislo - 1, chislo);
}
