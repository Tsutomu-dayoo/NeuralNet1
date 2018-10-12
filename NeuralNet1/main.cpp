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
    double a = 0.03;//gain
    double sum = 0.0;//重み付け総和
    int i;
    int num_0 = 0,num_1 = 0;
    
    for(i=0;i<num;i++){
        sum += w[i] * x[i];
    }
    p = 1 / (1 + exp(-a * sum));
    
    srand(10);
    
    for(i=0;i<100;i++){
        if(rand()<(p * RAND_MAX)){
            y = 1.0;
            num_1++;
        }
        else{
            y = 0.0;
            num_0++;
        }
    }
    //printf("理論値:%lf,y=1:%d,y=0:%d\n",(i+1)*p,num_1,num_0);
    printf("確率p:%lf, p(y=1):%lf\n",p,num_1 / (double)(i+1));
    
}
