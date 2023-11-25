#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
struct moment{
	int hours;
	int min;
	int sec;
};

int time_sec(struct moment time){
	int sum;

	sum=time.hours*3600 + time.min*60+time.sec;
	return sum;
}

struct moment sec_time(int sum, struct moment time1){
	
	time1.hours=sum/3600;
	sum=sum%3600;
	time1.min=sum/60;
	sum=sum%60;
	time1.sec=sum;
	return time1;
		
}
struct moment next_moment(struct moment time){
	int s=time_sec(time);
	s--;
	struct moment time2;
	time2=sec_time(s,time);
	return time2;
}

int main(){
	
	struct moment c_time;
	
	int n;
	printf("give time hh mm ss:");
	scanf("%i %i %i",&c_time.hours,&c_time.min,&c_time.sec);
	system("cls");
	n=time_sec(c_time);
	for(int i=0;i<n;i++){
		printf("%i:%i:%i\n",c_time.hours,c_time.min,c_time.sec);
		c_time=next_moment(c_time);
		Sleep(999);
		system("cls");

	}

	return 0;
}