#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

int main(){

    //最小値が最大値を上回らなくなるまでユーザーに値を設定させる。
    int minNum,maxNum;
    do
    {
        cout << "最小数を指定してください！ : ";
        cin >> minNum;
        cout << "最大数を指定してください！ : ";
        cin >> maxNum;
        if(minNum > maxNum) cout << "最小数より最大数の方が小さいです。やり直してください。" << endl;
   
    } while (minNum > maxNum);

    //http://vivi.dyndns.org/tech/cpp/random.html 一様乱数を作成
    random_device rnd;     
    mt19937 mt(rnd());
    uniform_int_distribution<> dist(minNum, maxNum);
    int correctNum = dist(mt);

    int guessNum;
    do
    {
        cout << "予想する数を入力してください。(最小数:" << minNum << ", 最大数:" << maxNum << ") : ";
        cin >> guessNum;
        if(correctNum == guessNum) cout << "正解です！" << endl;
        else cout << "違います、もう一度予想してみてください。" << endl;
    } while (correctNum != guessNum);
    

    return 0;
}