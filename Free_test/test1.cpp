# include <list>
# include <queue>
# include <iterator>
# include <iostream>

//25->10->35->76


using namespace std;
int main(void){
    list<int> test_list;
    list<int>::iterator it;
    test_list.push_back(25);
    test_list.push_back(10);
    test_list.push_back(35);
    test_list.push_back(76);
    test_list.pop_back();    
    for(it=test_list.begin();it!=test_list.end();it++){
        cout<<*it<<endl;
    }



        //簡單的講就是 傳入的時候不給定型別 這樣只要寫一個函數就好
}


