#include <iostream>
#include <signal.h>
#include "math.h"
#include "unistd.h"

#include "lib/gimbals/Gtracker.hpp"

//ctrl-c 
void ctrlc_handler(sig_atomic_t s){
    printf("\nCaught signal %d\n",s);
    tracker_deinit();
    exit(1);
}

int main(){
    signal(SIGINT,ctrlc_handler);
    tracker_init();

    //set gimbals pole
    BLDCMotor_SetPolePairs(0,11);
    BLDCMotor_SetPolePairs(1,11);

    BLDCMotor_IdleTorque(0,0,2000);
    float lastAngle;

    int motorId=1; //move this gimbal
    int encoderId=1; //encoder connector

    while(1){       
        GetInfoResult res=GetPWMEncoderAngle(encoderId,false);
        printf("\r Aggle from Encoder %.2f",res.fresult);
        
        float r=round(360-res.fresult);
        if(r!=lastAngle){
            BLDCMotor_MoveToAngle(motorId, r,0, 50,70);
        }
        lastAngle=r;
    }
    return 1;
}