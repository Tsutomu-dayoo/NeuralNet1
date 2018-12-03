//
//  SimultaneousEqu.cpp
//  NeuralNet1
//
//  Created by 山口勉 on 2018/10/02.
//  Copyright © 2018年 山口勉. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

#define num 5 + 1

double sigmoid(int i,double sum[num]);
double energy(void);
double SimultaneousEqu(double x[num]);
double ConstantValue(void);
double ObtaineTheta(int n,double c);
double ObtaineWeight(int n,int m,double theta_n,double theta_m,double c);

double a[num][num] =
{ {0.0,1.0,-1.0,-1.0,1.0,-2.0},
    {-3.0,2.0,0.0,1.0,-1.0,2.0},
    {-1.0,-1.0,2.0,0.0,-1.0,1.0},
    {1.0,0.0,-2.0,1.0,-1.0,0.0,},
    {-3.0,1.0,-1.0,2.0,-1.0,1.0,},
    {0.0,0.0,0.0,0.0,0.0,0.0}
};
double w[num][num];//重み
double x[num]; //後で変える//最初はダミーニューロン
double y[num];
double theta[num];

int main(void){
    static double sum[num];
    static double E; //エネルギー関数
    static double const_value;
    int i,j;
    
    const_value = ConstantValue();
    printf("C:%lf\n",const_value);
    for(i=0;i<num;i++){
        theta[i] = ObtaineTheta(i,const_value);
        printf("theta_%d:%lf",i,theta[i]);
        printf(",");
        if(i == num-1){
            printf("\n");
        }
    }
    for(i=0;i<num;i++){
        
        for(j=0;j<num;j++){
            w[i][j] = ObtaineWeight(i, j, theta[i], theta[j], const_value);
        }
    }
}

double sigmoid(int i,double sum[]){
    double p;
    double a = 0.5;
    p = 1 / (1 + exp(-a * sum[i]));
    
    return p;
}

double energy(void){
    double e = 0.0;
    int i,j;
    
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            e += w[i][j] * x[i] * x[j];
        }
    }
    return e;
}
//n,m番目の重みを求める、必要な値は予め求めておく
double ObtaineWeight(int n,int m,double theta_n,double theta_m,double c){
    int i;
    double E_nm = 0.0;
    
    for(i=0;i<num;i++){
        if(i == 0 || i == n || i == m){
            x[i] = 1.0;
        }
        else{
            x[i] = 0.0;
        }
    }
    E_nm = SimultaneousEqu(x) + theta_n + theta_m + c;
    return E_nm;
}

//n番目のthetaを求める、cは定数の値を予め求める
double ObtaineTheta(int n,double c){
    int i;
    double E_n = 0.0;
    
    for(i=0;i<num;i++){
        if(i == 0 || i == n){
            x[i] = 1.0;
        }
        else{
            x[i] = 0.0;
        }
    }
    E_n = SimultaneousEqu(x) - c;
    return E_n;
}
//定数を求める
double ConstantValue(void){
    int i;
    double C = 0.0;
    
    for(i=0;i<num;i++){
        if(i == 0){
            x[i] = 1.0;
        }
        else{
            x[i] = 0.0;
        }
    }
    C = SimultaneousEqu(x);
    return C;
}

double SimultaneousEqu(double x[num]){
    double E = 0.0;
    double sum = 0.0;
    int i,j;
    
    for(i=0;i<num;i++){
        
        for(j=0;j<num;j++){
            sum += a[i][j] * x[j];
        }
        E += sum * sum;
        sum = 0.0;
    }
    return E;
}
