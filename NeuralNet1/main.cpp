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

#define num 5 + 1

int main(void){
    double theta = -1.0;
    double w[num] = {theta,1.0,2.0,-1.0,3.0,2.0};
    double x[num] = {1.0,1.0,1.0,1.0,1.0,1.0}; //後で変える
    double y = 0.0;
    double p = 0.0;//確率
    double a = 1.5;//gain
    double sum = 0.0;//重み付け総和
    int i,j,k;
    
    for(i=0;i<num;i++){
        sum += w[i] * x[i];
    }
    //printf("sum-theta:%lf\n", sum);
    //p = 1 / (1 + exp(-a * sum));
    
    srand(10);
    
    for(i=0;i<11;i++){
        p = 1 / (1 + exp(-a * sum));
        int num_try = 100;
        for(j=0;j<8;j++){
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
    }
    //printf("理論値:%lf,y=1:%d,y=0:%d\n",(i+1)*p,num_1,num_0);
    
}

