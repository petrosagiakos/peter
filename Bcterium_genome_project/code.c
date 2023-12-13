#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
int find_start(FILE *f){ //takes the position of every start triplet from genes file
	char c=fgetc(f);
	char str_num[7];
	int cnt = 0;
	while(c!=','){
		
		str_num[cnt]=c;
		c=fgetc(f);
		cnt++;
	}
	int final=atoi(str_num);
	return final;
}

int find_stop(FILE *f){//takes the stop of every start triplet from genes01.dat file
	char c=fgetc(f);
	char str_num[7];
	int cnt = 0;
	while(c!='\n'){
		
		str_num[cnt]=c;
		c=fgetc(f);
		cnt++;
	}
	int final=atoi(str_num);
	return final;
}

void find_start_triplet(char tr[],int pos[][2], FILE *f, int i){//finds the start triplet in genome01.dat file
	
	fseek(f,pos[i][0]* sizeof(char),SEEK_SET);
	fread(tr,sizeof(char),3,f);
	tr[3]='\0';
	
}
void find_stop_triplet(char tr[],int pos[][2], FILE *f, int i){//finds the stop triplet in genome01.dat file
	
	fseek(f,pos[i][1]* sizeof(char),SEEK_SET);
	fread(tr,sizeof(char),3,f);
	tr[3]='\0';
	
}
int triplets_number(FILE *f,char tr[]){//loops in the genome01.dat file to find how many times its triplet appears
	int cnt1=0;
	fseek(f,0,SEEK_SET);
	while(!feof(f)){
		char tr_cur[4];
		fread(tr_cur,sizeof(char),3,f);
		tr_cur[3]='\0';
		int res=strcmp(tr,tr_cur);
		if(res==0){
			cnt1++;
		}
	}
	return cnt1;
}
int main(){
	FILE *genes=fopen("genes01.dat","rb");
	FILE *genome=fopen("genome01.dat","rb");//opens the 2 files
	int start_stop[299][2];
	
	int i=0;
	while(i<299){//loops within the gene01.dat file
		
		int start=find_start(genes);
	
		start_stop[i][0]=start;

		int stop=find_stop(genes);
		
		start_stop[i][1]=stop;
		
		i++;
	}
	
	fclose(genes);
	for(int k=0;k<299;k++){//loops within the genome01.dat file
		
		char triplet_start[4];
		char triplet_stop[4];

		find_start_triplet(triplet_start,start_stop,genome,k);
		int cnt_start=triplets_number(genome,triplet_start);

		find_stop_triplet(triplet_stop,start_stop,genome,k);
		int cnt_stop=triplets_number(genome,triplet_stop);

		printf("%i. start=%s appears %i times \n stop=%s appears %i times \n\n",k,triplet_start,cnt_start,triplet_stop,cnt_stop);
	}
	fclose(genome);






	return 0;
}
