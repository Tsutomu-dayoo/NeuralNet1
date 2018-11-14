//
//  main.cpp
//  NeuralNet1
//
//  Created by 山口勉 on 2018/10/02.
//  Copyright © 2018年 山口勉. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define num 4 + 1

double sigmoid(int i,double sum[num]);
double energy(void);

double a;
double w[num][num];//重み
double x[num] = {1.0,1.0,1.0,1.0,1.0}; //後で変える//最初はダミーニューロン
double y[num] = {0.0,0.0,0.0,0.0,0.0};

int main(void){
    double theta = -0.5;
    static double sum[num];
    //static double p = 0.0;//確率
    static double E; //エネルギー関数
    int i,j,k;
    //重み決め
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(i == j){
                w[i][j] = 0.0;
            }
            else if(i == 0 || j == 0){
                w[i][j] = -theta;
            }
            else{
                w[i][j] = -1.0;
            }
        }
        sum[i] = 0.0;//和を初期化
    }
    
    srand(10);
    printf("x1:%lf,x2:%lf,x3:%lf,x4:%lf\n",x[1],x[2],x[3],x[4]);
    printf("↑xの初期値\n");
    for(i=0;i<100;i++){
        for(j=0;j<num;j++){
            if(j != 0){
                //printf("j=%d\n",j);
                for(k=0;k<num;k++){
                    x[0] = 1.0;
                    sum[j] += w[k][j] * x[k];
                    //printf("sum[%d]:%lf\n",j,sum[j]);
                }
                //xの値を更新
                if(sum[j]>=0){
                    y[j] = 1.0;
                }
                else{
                    y[j] = 0.0;
                }
                x[j] = y[j];
                printf("x1:%lf,x2:%lf,x3:%lf,x4:%lf\n",x[1],x[2],x[3],x[4]);
                //エネルギーの評価
                E = energy();
                printf("E:%lf\n",-0.5*E);
            }
            sum[j] = 0.0;
        }
    }
}

double sigmoid(int i,double sum[]){
    double p;
    //double a;
    a = 0.5;
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
