/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/equal-groups/problem
 * Title: hw3_2.cpp
 * Abstract: This program partitions n positive integers into two disjoint sets with the same sum.
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 2-12-2020
 */


#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> partition(string s, vector<int> v);
int checkSum(int num);
string stringChange(int num);

int main(){
    int n;
    int temp;
    cin >> n;
    vector<int> numbers;
    vector<int> tempVect;
    for(int i = 0; i < n; i++){
        cin >> temp;
        numbers.push_back(temp);
    }
    if(n == 0){
        cout << "0";
    } else {
        for(int i = 0; i < (pow(2, n) - 1) / 2; i++){
            string comboString;
            int size = n;
            int digits = checkSum(i);
            int zeros = size - digits;
            while(zeros > 0){
                comboString += "0";
                zeros--;
            }
            comboString += stringChange(i);
            vector<int> result = partition(comboString, numbers);
            if(result.size() != 0){
                tempVect = result;
            }else{
                continue;
            }
            cout<< "Equal Set: ";
        }
        if(tempVect.size() == 0){
            cout << "Equal Set: 0";
        }else{
            for(int i = 0; i < tempVect.size(); i++){
                cout << tempVect[i] << " ";
            }
        }
    }
}

int checkSum(int num){
    int counter = 0;
    if(num == 0){
        return 1;
    }
    while(num > 0){
        num = num / 2;
        counter++;
    }
    return counter;
}

vector<int> partition(string s, vector<int> v){
    vector<int> subset1, subset2;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < v.size(); i++){
        if(s[i] == '0'){
            subset1.push_back(v[i]);
            sum1 += v[i];
        }else{
            subset2.push_back(v[i]);
            sum2 += v[i];
        }
    }
    if(sum1 == sum2){
        sort(subset1.begin(), subset1.end());
        sort(subset2.begin(), subset2.end());
        if(subset1[0] < subset2[0]){
            return subset1;
        }else{
            return subset2;
        }
    }else{
        return {};
    }
}


string stringChange(int num){
    string s1;
    string s2;
    if(num == 0){
        s2 += "0";
    }
    while(num > 0){
        s1 += to_string(num % 2);
        num = num/2;
    }
    for(int i = s1.length() - 1; i >= 0; i--){
        s2 += s1[i];
    }
    return s2;
}

