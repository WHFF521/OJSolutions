#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
// TLE
int main(){
    double D;
    while(cin>>D&&D!=-1){
        double hour = 0;
        double minute = 0;
        double second = 0;
        double time = 0;
        for(int i=0;i<=60*60*12*6*5;i++){
            second +=0.2;
            minute += 0.2/60.0;
            hour += 1.0/60.0/60.0;
            second = fmod(second,360.0);
            minute = fmod(minute,360.0);
            hour = fmod(hour,360.0);
            double angle1 = abs(hour-minute);
            double angle2 = abs(second-minute);
            double angle3 = abs(hour-second);
            if(angle1>=D&&angle2>=D&&angle3>=D
            &&angle1<=360-D&&angle2<=360-D&&angle3<=360-D){
                time++;
            }
        }
        printf("%.3f\n",time*100/6/5/12/60/60);
    }
    return 0;
}