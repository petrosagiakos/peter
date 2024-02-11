//Πρόγραμμα Κατανάλωσης Ενέργειας

#include <stdio.h> //Συμπερίληψη κατάλληλων βιβλιοθηκών.
#include <stdlib.h>
#include <string.h>

void extract_data(char string1[],char data[][11],const char *split){ //συνάρτηση εξαγωγής δεδομένων από συμβολοσειρά.

	char *extraction = strtok(string1,split); //Παίρνει το πρώτο κομμάτι απο την συμβολοσειρά.
	int i=0;

	while(extraction!=NULL){ //Μέχρι η συμβολοσειρά να επιστρέψει NULL.

		strncpy(data[i], extraction, 10); //Αντιγράφει 10 χαρακτήρες(το μέγεθος της μεγαλύτερης συμβολοσειράς που θα εξαχθεί) από την extraction στην data[i]. 
        	data[i][10] = '\0'; //Στον 11ο χαρακτήρα βάζει τον null terminator.

		extraction = strtok(NULL,split); //Παίρνει το επόμενο κομμάτι της συμβολοσειράς.
		i++;
	}
}

struct time{ //Ορισμός τύπου δεδομένων struct time.
	int hours;
	int min;
	int sec;
};

struct date{ //Ορισμός τύπου δεδομένων struct date.
	int day;
	int month;
	int year;
};

struct consumption{ //Ορισμός τύπου δεδομένων struct consumption.
	double cons1;
	double cons2;
	double cons3;
};
struct average{ //Ορισμός τύπου δεδομένων struct average.

	double c1sum;
	int c1cnt;

	double c2sum;
	int c2cnt;

	double c3sum;
	int c3cnt;
};

void appear_specific(struct time time1,struct date date1, struct consumption cons ){ //Συνάρτηση εμφάνισης συγκεκριμένων εγγραφών.
	if((date1.year==2008)&&(date1.month==11)&&(date1.day==6)&&(time1.hours==13)){ //Εμφανίζει τις εγγραφές που έχουν ημερομηνία 6/11/2008 και ώρα 13.
		printf("%i:%i:%i-%i.%i.%i-%lf-%lf-%lf\n\n ",date1.day,date1.month,date1.year,time1.hours,time1.min,time1.sec,cons.cons1,cons.cons2,cons.cons3);
	}
	
}

void average_cosumption(struct time time1, struct consumption cons, struct average average1[]){ //Συναρτηση υπολογισμού μέσου όρου
	
		
			average1[time1.hours].c1sum+=cons.cons1; //Αθροίζει την τιμή της πρώτης κατανάλωσης κάθε εγγραφής.
			average1[time1.hours].c2sum+=cons.cons2; //Αθροίζει την τιμή της δεύτερης κατανάλωσης κάθε εγγραφής.
			average1[time1.hours].c3sum+=cons.cons3; //Αθροίζει την τιμή της τρίτης κατανάλωσης κάθε εγγραφής.
			
			if(cons.cons1!=0.0){ 
				average1[time1.hours].c1cnt++; //Μετράει όλες τις μη μηδενικές τιμές της πρώτης κατανάλωσης.
			}
			if(cons.cons2!=0.0){
				average1[time1.hours].c2cnt++; //Μετράει όλες τις μη μηδενικές τιμές της δεύτερης κατανάλωσης.
			}
			if(cons.cons3!=0.0){
				average1[time1.hours].c3cnt++; //Μετράει όλες τις μη μηδενικές τιμές της τρίτης κατανάλωσης.
			}
			 
		
	
}

void appear_final_results(struct average av1[]){ //Συνάρτηση εμφάνισης των μέσων τιμών. 

	printf("------------------------\n");
	
	for(int i=0;i<24;i++){
		printf("%i  %.2lf  %.2lf  %.2lf \n",i,av1[i].c1sum/av1[i].c1cnt,av1[i].c2sum/av1[i].c2cnt,av1[i].c3sum/av1[i].c3cnt);
		//Διατρέχει τον πίνακα τύπου struct average av1 και εμφανίζει την μέση τιμή των καταναλώσεων για κάθε ώρα.
	}
}

int main(){

	FILE *f=fopen("power_consumption.txt","rt"); //Άνοιγμα αρχείου.
	char *string1; //Δήλωση pointer.
	size_t space=100;
	string1 = (char *)malloc(space * sizeof(char)); //Δυναμική εκχώρηση μνήμης.
	getline(&string1,&space,f); //Παίρνει την πρώτη γραμμή του αρχείου η οποία περιέχει τους τίτλους κάθε στήλης δεδομένων.

	struct average av1[24]; //Δήλωση πίνακα τύπου struct average με 24 θέσεις.

	for(int i=0;i<24;i++){ //Αρχικοποίση του πίνακα
		av1[i].c1sum=0.0;
		av1[i].c1cnt=0;

		av1[i].c2sum=0.0;
		av1[i].c2cnt=0;

		av1[i].c3sum=0.0;
		av1[i].c3cnt=0;
	}
	
	printf("Please, wait a moment\n");
	
	while(!feof(f)){ //Βρόγχος Επανάληψης μεχρι το τέλος του αρχείου.

		
	
		char data[5][11];
		char date[3][11];
		char time[3][11];

		string1 = (char *)malloc(space * sizeof(char));
		getline(&string1,&space,f);

	
		extract_data(string1,data," "); //Εξαγωγή δεδομένων από την συμβολοσειρά string1 χρησιμοποιόντας τον χαρακτήρα κενό(" ")
						//και τα αποθηκεύει στον πινακα συμβολοσειρών data.

		extract_data(data[0],date,"/");//Εξαγωγή δεδομένων από την συμβολοσειρά string1 χρησιμοποιόντας τον χαρακτήρα back slash("/")
						//και τα αποθηκεύει στον πινακα συμβολοσειρών date.
	
		extract_data(data[1],time,":");//Εξαγωγή δεδομένων από την συμβολοσειρά string1 χρησιμοποιόντας τον χαρακτήρα κενό(" ")
						//και τα αποθηκεύει στον πινακα συμβολοσειρών data.
	
		struct date the_day; //Δημιουργία struct date.
		struct time the_time; //Δημιουργία struct time.
		struct consumption the_cons; //Δημιουργία struct consumption.
	
		the_day.day=atoi(date[0]); //Μετατροπή της συμβολοσειράς date[0] σε ακέραιο και εκχώρησή της στην μεταβλητή day του struct the_day.
		the_day.month=atoi(date[1]); //Μετατροπή της συμβολοσειράς date[1] σε ακέραιο και εκχώρησή της στην μεταβλητή month του struct the_day.
		the_day.year=atoi(date[2]); //Μετατροπή της συμβολοσειράς date[2] σε ακέραιο και εκχώρησή της στην μεταβλητή year του struct the_day.	
	
		the_time.hours=atoi(time[0]); //Μετατροπή της συμβολοσειράς time[0] σε ακέραιο και εκχώρησή της στην μεταβλητή hours του struct the_time.
		the_time.min=atoi(time[1]); //Μετατροπή της συμβολοσειράς time[1] σε ακέραιο και εκχώρησή της στην μεταβλητή day του struct the_time.
		the_time.sec=atoi(time[2]); //Μετατροπή της συμβολοσειράς time[2] σε ακέραιο και εκχώρησή της στην μεταβλητή day του struct the_time.

		char *ptr;
		the_cons.cons1=strtod(data[2],&ptr); //Μετατροπή της συμβολοσειράς data[2] σε double και εκχώρησή της στην μεταβλητή cons1 του struct the_consumption.
		the_cons.cons2=strtod(data[3],&ptr);//Μετατροπή της συμβολοσειράς data[3] σε double και εκχώρησή της στην μεταβλητή cons2 του struct the_consumption.
		the_cons.cons3=strtod(data[4],&ptr);//Μετατροπή της συμβολοσειράς data[4] σε double και εκχώρησή της στην μεταβλητή cons3 του struct the_consumption.

		appear_specific(the_time,the_day,the_cons);
		average_cosumption(the_time,the_cons,av1);
		
	}

	appear_final_results(av1);	

	fclose(f);

	return 0;
}