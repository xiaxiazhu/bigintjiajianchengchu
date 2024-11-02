//
//  bigIntDemo.cpp
//  cplusTimu
//
//  Created by zhuzhuxia on 2024/10/24.
//

#include "BigInt.hpp"


BigInt factorial(BigInt n){
//        BigInt num1("1");
//        if (num1 >= n ) {
//            return num1;
//        }else{
//            return n*factorial(n-num1);
//        }
    return BigInt("1");
}



bool isPrime(int x){

    if(x <= 1){ return false;}
    if(x==2||x==3) {return true;}

    for (int i = 2; i <= sqrt(x); i++)
    {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

vector<int> nthPrimeMax(int n) {

//    int n;
//    cin>>n;

    vector<int> primeNumList = {};

    int di=0;

    while (true) {
            di++;
            if (isPrime(di)) {
                primeNumList.push_back(di);
            }

            if (primeNumList.size() == n) {
                break;
            }
    }

    return primeNumList;
}

int runBigIntDemo() {

////    cout<<factorial(11)<<endl;
//    string n;
//    cin >> n;
//
//
//
//    BigInt facValue = factorial(n);
//
//    int dn=0; // 切换质数
//    int i = 1; // 到底步长，取质数
//    vector<int> pArray={};// 质数列表
//
//    while (true) {
//        int a = 0 ;
//        int bc = 100; //步长
//
//        if (dn==0) {
//            //init parray
//            pArray = nthPrimeMax(bc*i);
//        }
//        if (dn>(bc*i)){
//                i++;
//                pArray = nthPrimeMax(bc*i);
//            }
//
//        int p = pArray[dn];// 2 3 5 7 11 13 17 19 23 27 29
//
//            string pStr = to_string(p);
//
//        BigInt bigP(pStr);
//
////        facValue('asdf');
//
//            while (facValue % bigP == BigInt("0")) { // 整除
//                cout<<facValue<<endl;
//                facValue=facValue/bigP;
//                a++;
//            }// 不能整除
//
//            cout << p <<" "<<a<<endl;
//            if (facValue==BigInt("1")) {
//                break;
//            }
//        dn++; //切换质数
//    }
//
//    // 2 3 5 7 11 13 17 19 23
////    cout<<nthPrimeMax(9)<<endl;
//
    return 1;
}

