# include <iostream>
# include <iomanip>
using namespace std;
int main(){
    cout <<"Name" << "|" << 123456 <<endl;
    cout << "\nUsing setw... \n" <<endl;
    cout << setw(10) << "Name" << setw(2) << "|" <<setw(4) << 123456 <<endl;
}