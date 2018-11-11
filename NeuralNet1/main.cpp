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

double summation(int i,int j,double *w[num][num],double *x[num]);
double sigmoid(int i,double sum[num]);

int main(void){
    double theta = -0.5;
    double w[num][num] =
    { {0.0,-theta,-theta,-theta,-theta},
        {0.0,0.0,-1.0,-1.0,-1.0},
        {0.0,-1.0,0.0,-1.0,-1.0},
        {0.0,-1.0,-1.0,0.0,-1.0},
        {0.0,-1.0,-1.0,-1.0,0.0}
    };
    static double x[num] = {1.0,0.0,0.0,0.0,0.0}; //後で変える//最初はダミーニューロン
    static double sum[num];
    static double y[num] = {0.0,0.0,0.0,0.0,0.0};
    static double p = 0.0;//確率
    static double E; //エネルギー関数
    static double E0; //１ステップ前のエネルギー関数
    double a = 0.5;//gain
    int i,j,k;
    
    for(i=0;i<100;i++){
        
        for(j=0;j<num;j++){
            
            for(k=0;k<num;k++){
                sum[j] += w[k][j] * x[k];
                p = sigmoid(j,sum);
                
                if(rand()<(p * RAND_MAX)){
                    y[j] = 1.0;
                }
                else{
                    y[j] = 0.0;
                }
                
                x[j] = y[j];
                E += w[j][k] * x[j] * x[k];
                //printf("E:%lf\n",E);
            }
            printf("x1:%lf,x2:%lf,x3:%lf,x4:%lf\n",x[1],x[2],x[3],x[4]);
        }
        
    }
    
    
    srand(10);
    
    /*
    for(i=0;i<1;i++){
        p = 1 / (1 + exp(-a * sum));
        int num_try = 100;
        for(j=0;j<7;j++){
            int num_0 = 0,num_1 = 0;
            for(k=0;k<num_try;k++){
                if(rand()<(p * RAND_MAX)){
                    y = 1.0;
                    num_1++;
                }
                else{
                    y = 0.0;
                    num_0++;
                }
            }
            printf("ゲイン:%3f 試行回数:%11d 確率p:%lf, p(y=1):%lf\n",a,k,p,num_1 / (double)k);
            num_try = num_try * 10;
        }
        printf("------\n");
        a -= 0.1;
    }*/
    
}

double sigmoid(int i,double sum[]){
    double p;
    double a;
    
    p = 1 / (1 + exp(-a * sum[i]));
    
    return p;
}
