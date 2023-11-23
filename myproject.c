#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void subject_header()
{
	printf("%-5s%-20s%6s\n", "ID", "TITLE", "YEAR");
}
void student_header()
{
	printf("%-5s %-20s%-9s%-9s%-14s%-25s%-15s\n", "ID", "NAME", "GENDER", "CLASS", "STUDY YEAR",\
		"ADDRESS", "P-Number");
}
void score_header(){
	printf("%-5s%-15s%-15s%-15s%-15s\n","NAME","MATH","KHMER","ENGLISH","TOTAL");
}
void input_subject();
void output_subject();
void search_subject();
void update_subject();
void append_subject();
void del_subject();
void sort_on_screen_subject();
void sort_in_file_subject();

void input_student();
void output_student();
void search_student();
void update_student();
void append_student();
void del_student();
void sort_on_screen_student();
void sort_in_file_student();
void delay(int);

void input_score();
void output_score();
void update_score();


void delay(int delay){
	int now=time(NULL);
	int later=now+delay;
	while(now<=later)now=time(NULL);
}

//void loadingBar(){
//	char a = 177;
//	char b = 176;
//	int j=10;
//	int i;
//	system("color a");
//	printf("\n\n\t\t\t\tloading....");
//	printf("\n\t\t\t\t");
//	for(i=0;i<j;i++)
//	{
//		printf("%c", a);
//		delay(0.1);
//	}
//	printf("\r\t\t\t\t");
//	for(i = 0; i < j; i++)
//	{
//		printf("%c", b);
//		delay(0.1);
//	}
//	system("cls");
//	system("color 7");
//}
typedef struct Subject_info{
	int id, year;
	char title[50];
}subject;
typedef struct Student_info{
	int id, phone, year;
	char name[50], address[100], gender[10], sclass[50];
}student;
typedef struct Score{
	int id;
	int scm,sck,sce;
	int total;
}score;
void menu(){
	printf("1. Input\n");
	printf("2. Output\n");
	printf("3. Search\n");
	printf("4. Append\n");
	printf("5. Update\n");
	printf("6. Sort On Screen\n");
	printf("7. Sort and write into file\n");
	printf("8. Delete\n");
}
int main(){
	int op_menu, op_subject, op_student,op_score, n, i;
	FILE *subject_info;
	struct Subject_info si[100];
	struct Student_info sti[100];
	struct Score sc[100];
//	loadingBar();
	do{
		
		printf("==================== Information ====================\n");
		printf("1. Subject	Information\n");
		printf("2. Student	Information\n");
		printf("3. Student	Score\n");
		printf("4. Exit Program\n");
		printf("Please choose an option = ");scanf("%d", &op_menu);
		system("cls");
		switch(op_menu)
		{
			case 1:{	
				do{
					//loadingBar();
					printf("==================== Subject Information ====================\n");
					menu();
					printf("Please choose an option = ");scanf("%d", &op_subject);
					system("cls");
					switch(op_subject)
					{
						case 1:{
							input_subject();
							system("cls");
							break;
						}
						case 2:{
							output_subject();
							getch();
							system("cls");
							break;
						}
						case 3:{
							search_subject();
							getch();
							system("cls");
							break;
						}
						case 4:{
							append_subject();
							system("cls");
							break;
						}
						case 5:{
							update_subject();
							system("cls");
							break;
						}
						case 6:{
							sort_on_screen_subject();
							system("cls");
							break;
						}
						case 7:{
							sort_in_file_subject();
							system("cls");
							break;
						}
						case 8:{
							del_subject();
							system("cls");
							break;
						}
						case 0:{
							printf("Returning to menu.....");
							delay(1);
							system("cls");
							break;
						}
						default:{
							printf("Option is not available!\n");
							printf("Please choose a correct option..\n");
							getch();
							system("cls");
							break;
						}		
					}
				}while(op_subject!=0);
			break;
			}
			case 2:{
				do{
					printf("==================== Student Information ====================\n");
					menu();
					printf("Please choose an option = ");scanf("%d", &op_student);
					system("cls");
					switch(op_student)
					{
						case 1:{
							input_student();
							system("cls");
							break;
						}	
						case 2:{
							output_student();
							getch();
							system("cls");
							break;
						}
						case 3:{
							search_student();
							getch();
							system("cls");
							break;
						}
						case 4:{
							append_student();
							system("cls");
							break;
						}
						case 5:{
							update_student();
							system("cls");
							break;
						}
						case 6:{
							sort_on_screen_student();
							system("cls");
							break;
						}
						case 7:{
							sort_in_file_student();
							system("cls");
							break;
						}
						case 8:{
							del_student();
							system("cls");
							break;
						}
						case 0:{
							printf("Returning to menu.....");
							delay(1);
							system("cls");
							break;
						}
						default:{
							printf("Option is not available!\n");
							printf("Please choose a correct option..\n");
							getch();
							system("cls");
							break;
						}
					}
				}while(op_student != 0);
			break;
			}
			case 3:{
				do{
				
				    printf("==================== Student Information ====================\n");
					printf("1. Input\n");
					printf("2. Output\n");
					printf("3. Update\n");
					printf("Please choose an option = ");scanf("%d", &op_score);
					system("cls");
					switch(op_score)
					{
						case 1:{
							input_score();
							getch();
							system("cls");
							break;
						}
						case 2:{
							output_score();
							getch();
							system("cls");
							break;
						}
						case 3:{
							update_score();
							system("cls");
							break;
						}
					}
			    }while(!op_score);
			break;
			}
		}
	}while(op_menu != 0);
}

//###################################Subject######################################
void input_subject()
{
	int nsubject,i;
	FILE *subject_info;
	subject *si;
	
	printf("Enter number of subject = ");scanf("%d", &nsubject);
	si = (subject *)calloc(nsubject, sizeof(subject));
	subject_info = fopen("subject_test.txt", "ab");
	
	for(i = 0; i < nsubject; i++)
	{
		printf("\t\tSubject #%d\n", i+1);
		printf("ID	= ");scanf("%d", &si[i].id);
		printf("Title	= ");fflush(stdin);gets(si[i].title);
		printf("Year	= ");scanf("%d", &si[i].year);
		
		fwrite(&si[i], sizeof(subject), 1, subject_info);
	}
	fclose(subject_info);
}
void output_subject()
{
	FILE *subject_info;
	subject si;
	subject_info = fopen("subject_test.txt", "rb");
	subject_header();
	while(fread(&si, sizeof(subject), 1, subject_info))
	{
		printf("%04d %-20s%6d\n", si.id, si.title, si.year);
//		printf("ID	= %d\n", si.id);
//		printf("Title	= %s\n", si.title);
//		printf("Year	= %d\n", si.year);
	}
	fclose(subject_info);
}
void search_subject()
{
	FILE *subject_info;
	subject si;
	int idsearch, found = 0;
	subject_info = fopen("subject_test.txt", "rb");
	printf("Enter subject id to search = ");scanf("%d", &idsearch);
	
	while(fread(&si, sizeof(subject), 1, subject_info))
	{
		if( idsearch == si.id )
		{
			found = 1;
			subject_header();
			printf("%04d%-20s%6d\n", si.id, si.title, si.year);
		}
	}
	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	fclose(subject_info);
}
void update_subject()
{
	FILE *subject_info;
	FILE *tmp;
	subject si;
	int idsearch, found = 0;
	subject_info = fopen("subject_test.txt", "rb");
	tmp = fopen("tmp.txt", "wb");
	printf("Enter subject id to update = ");scanf("%d", &idsearch);
	
	while(fread(&si, sizeof(subject), 1, subject_info))
	{
		if( idsearch == si.id )
		{
			found = 1;
			subject_header();
			printf("%04d %-20s%6d\n", si.id, si.title, si.year);
			printf("Enter new information:\n");
			printf("ID	= ");scanf("%d", &si.id);
			printf("Title	= ");fflush(stdin);gets(si.title);
			printf("Year	= ");scanf("%d", &si.year);
		}
		fwrite(&si, sizeof(subject), 1, tmp);
	}
	
	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	fclose(subject_info);
	fclose(tmp);
	if(found)
	{   printf("hi\n");
		tmp = fopen("tmp.txt", "rb");
		subject_info = fopen("subject_test.txt", "wb");
		while(fread(&si, sizeof(subject), 1, tmp))
		{
			fwrite(&si, sizeof(subject), 1, subject_info);
		}
		printf("Updated....\n");
		fclose(tmp);
		fclose(subject_info);
	}
}
void del_subject()
{
	FILE *subject_info;
	FILE *tmp;
	subject si;
	int idsearch, found = 0;
	subject_info = fopen("subject_test.txt", "rb");
	tmp = fopen("tmp.txt", "wb");
	printf("Enter subject id to delete = ");scanf("%d", &idsearch);
	
	while(fread(&si, sizeof(subject), 1, subject_info))
	{
		if( idsearch == si.id )
		{
			found = 1;
			printf("ID Found...\n");
			subject_header();
			printf("%04d %-20s%6d\n", si.id, si.title, si.year);
			delay(1);
		}
		else{
			fwrite(&si, sizeof(subject), 1, tmp);	
		}	
	}
	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	fclose(subject_info);
	fclose(tmp);
	if(found)
	{
		tmp = fopen("tmp.txt", "rb");
		subject_info = fopen("subject_test.txt", "wb");
		while(fread(&si, sizeof(subject), 1, tmp))
		{
			fwrite(&si, sizeof(subject), 1, subject_info);
		}
		printf("Deleted....\n");
		fclose(tmp);
		fclose(subject_info);
	}
	fclose(subject_info);
}
void append_subject(){
	int nsubject,i;
	FILE *subject_info;
	subject *si;
	
	printf("Enter number of subject = ");scanf("%d", &nsubject);
	si = (subject *)calloc(nsubject, sizeof(subject));
	subject_info = fopen("subject_test.txt", "ab");
	
	for(i = 0; i < nsubject; i++)
	{
		printf("\t\tNew Subject #%d\n", i+1);
		printf("ID	= ");scanf("%d", &si[i].id);
		printf("Title	= ");fflush(stdin);gets(si[i].title);
		printf("Year	= ");scanf("%d", &si[i].year);
		
		fwrite(&si[i], sizeof(subject), 1, subject_info);
	}
	fclose(subject_info);
}
void sort_on_screen_subject()
{
	FILE *subject_info;
	subject *si, tmp;
	int i, j, nsubject;
	subject_info = fopen("subject_test.txt", "rb");
	fseek(subject_info, 0, SEEK_END);
	nsubject = ftell(subject_info) / sizeof(subject);
	rewind(subject_info);
	
	si = (subject *)calloc(nsubject, sizeof(subject));
	for(i = 0; i < nsubject; i++)
	{
		fread(&si[i], sizeof(subject), 1, subject_info);
	}
	
	for(i = 0; i < nsubject; i++)
	{
		for(j = i ; j < nsubject; j++)
		{
			if( si[i].id > si[j].id)
			{
				tmp   = si[i];
				si[i] = si[j];
				si[j] = tmp;
			}
		}
	}
	subject_header();
	for(i = 0; i < nsubject; i++)
	{
		printf("%04d %-20s%6d\n", si[i].id, si[i].title, si[i].year);
	}
	printf("\4 Sort Sucessfull....\n");
	
	fclose(subject_info);
}
void sort_in_file_subject()
{
	FILE *subject_info;
	subject *si, tmp;
	int i, j, nsubject;
	subject_info = fopen("subject_test.txt", "rb");
	fseek(subject_info, 0, SEEK_END);
	nsubject = ftell(subject_info) / sizeof(subject);
	rewind(subject_info);
	
	si = (subject *)calloc(nsubject, sizeof(subject));
	for(i = 0; i < nsubject; i++)
	{
		fread(&si[i], sizeof(subject), 1, subject_info);
	}
	fclose(subject_info);
	for(i = 0; i < nsubject; i++)
	{
		for(j = i ; j < nsubject; j++)
		{
			if( si[i].id > si[j].id)
			{
				tmp   = si[i];
				si[i] = si[j];
				si[j] = tmp;
			}
		}
	}
	subject_info = fopen("subject_test.txt", "wb");
	subject_header();
	for(i = 0; i < nsubject; i++)
	{
		printf("%04d %-20s%6d\n", si[i].id, si[i].title, si[i].year);
		fwrite(&si[i], sizeof(subject), 1, subject_info);
	}
	fclose(subject_info);
	printf("\4 Sort and write sucessfull....\n");
}
//###################################Subject######################################

//###################################Student######################################
void input_student()
{
	FILE *student_info;
	student *st;
	int i, n_student;
	printf("Enter number of student = ");scanf("%d", &n_student);
	st = (student *)calloc(n_student, sizeof(student));
	
	student_info = fopen("student_info.txt", "ab");
	if(!student_info)
	{
		printf("Error openning file..\n");
	}
	else{
		for(i = 0; i < n_student ; i++)
		{
			printf("\t\t\tStudent #%d\n", i+1);
			printf("ID	= ");scanf("%d", &st[i].id);
			printf("Name	= ");fflush(stdin);gets(st[i].name);
			printf("Gender	= ");gets(st[i].gender);
			printf("Class	= ");gets(st[i].sclass);
			printf("Study Year	= ");fflush(stdin);scanf("%d", &st[i].year);
			printf("Address	= ");fflush(stdin);gets(st[i].address);
			printf("Phone Number	= ");scanf("%d", &st[i].phone);
			fwrite(&st[i], sizeof(student), 1, student_info);
		}
		printf("Data Record Successfully..\n");
	}
	
	fclose(student_info);
}

void output_student()
{
	FILE *student_info;
	student st;
	student_info = fopen("student_info.txt", "rb");
	if(!student_info)
	{
		printf("Error openning file...\n");
	}
	student_header();
	while(fread(&st, sizeof(student), 1, student_info))
	{
		printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st.id, st.name, st.gender, st.sclass, st.year, st.address, st.phone);
	}
	fclose(student_info);
}
void search_student()
{
	FILE *student_info;
	student st;
	int idsearch, found = 0;
	printf("Enter student id to search = ");scanf("%d", &idsearch);
	student_info = fopen("student_info.txt", "rb");
	while(fread(&st, sizeof(student), 1, student_info))
	{
		if( idsearch == st.id)
		{
			printf("ID Found....\n");
			found = 1;
			delay(100);
			system("cls");
			student_header();
			printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st.id, st.name, st.gender, st.sclass, st.year,\
			st.address, st.phone);
		}
	}
		if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	fclose(student_info);
}
void append_student()
{
	FILE *student_info;
	student *st;
	int i, new_student;
	printf("Enter number of student to append = ");scanf("%d", &new_student);
	st = (student *)calloc(new_student, sizeof(student));
	
	student_info = fopen("student_info.txt", "ab");
	if(!student_info)
	{
		printf("Error openning file..\n");
	}
	else{
		for(i = 0; i < new_student ; i++)
		{
			printf("\t\t\tNew Student #%d\n", i+1);
			printf("ID	= ");scanf("%d", &st[i].id);
			printf("Name	= ");fflush(stdin);gets(st[i].name);
			printf("Gender	= ");gets(st[i].gender);
			printf("Class	= ");gets(st[i].sclass);
			printf("Study Year	= ");fflush(stdin);scanf("%d", &st[i].year);
			printf("Address	= ");fflush(stdin);gets(st[i].address);
			printf("Phone Number	= ");scanf("%d", &st[i].phone);
			fwrite(&st[i], sizeof(student), 1, student_info);
		}
		printf("Data Record Successfully..\n");
	}
	
	fclose(student_info);
}
void update_student()
{
	FILE *student_info;
	FILE *tmp;
	student st;
	int idsearch, found = 0;
	printf("Enter student id to update = ");scanf("%d", &idsearch);
	
	tmp = fopen("tmp_student.txt", "wb");
	student_info = fopen("student_info.txt", "rb");
	
	while(fread(&st, sizeof(student), 1, student_info))
	{
		if( idsearch == st.id)
		{
			printf("ID Found....\n");
			found = 1;
			delay(100);
			system("cls");
			student_header();
			printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st.id, st.name, st.gender, st.sclass, st.year,\
			st.address, st.phone);
			printf("\t()New information for student)\n");
			printf("ID	= ");scanf("%d", &st.id);
			printf("Name	= ");fflush(stdin);gets(st.name);
			printf("Gender	= ");gets(st.gender);
			printf("Class	= ");gets(st.sclass);
			printf("Study Year	= ");fflush(stdin);scanf("%d", &st.year);
			printf("Address	= ");fflush(stdin);gets(st.address);
			printf("Phone Number	= ");scanf("%d", &st.phone);
		}
		fwrite(&st, sizeof(student), 1, tmp);
	}
	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	fclose(tmp);
	fclose(student_info);
	
	if(found)
	{
		tmp = fopen("tmp_student.txt", "rb");
		student_info = fopen("student_info.txt", "wb");
		
		while(fread(&st, sizeof(student), 1, tmp))
		{
			fwrite(&st, sizeof(student), 1, student_info);
		}
		
		fclose(tmp);
		fclose(student_info);	
	}
}
void sort_on_screen_student()
{
	FILE *student_info;
	student *st, tmp;
	int n_student, i, j;
	student_info = fopen("student_info.txt", "rb");
	fseek(student_info, 0, SEEK_END);
	n_student = ftell(student_info) / sizeof(student);
	rewind(student_info);
	
	st = (student *)calloc(n_student, sizeof(student));
	
	for(i = 0; i < n_student; i++)
	{
		fread(&st[i], sizeof(student), 1, student_info);
	}
	
	for(i = 0; i < n_student; i++)
	{
		for(j = i; j < n_student; j++)
		{
			if( st[i].id > st[j].id)
			{
				tmp   = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}		
	}	
	// output
	student_header();
	for(i = 0; i < n_student; i++)
	{
			printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st[i].id, st[i].name, st[i].gender, st[i].sclass,\
			st[i].year, st[i].address, st[i].phone);
	}
	printf("Sort Successfully...\n");
	
	fclose(student_info);
}
void sort_in_file_student()
{
	FILE *student_info;
	student *st, tmp;
	int n_student, i, j;
	student_info = fopen("student_info.txt", "rb");
	fseek(student_info, 0, SEEK_END);
	n_student = ftell(student_info) / sizeof(student);
	rewind(student_info);
	
	st = (student *)calloc(n_student, sizeof(student));
	
	for(i = 0; i < n_student; i++)
	{
		fread(&st[i], sizeof(student), 1, student_info);
	}
	fclose(student_info);
	for(i = 0; i < n_student; i++)
	{
		for(j = i; j < n_student; j++)
		{
			if( st[i].id > st[j].id)
			{
				tmp   = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
		}		
	}	
	student_info = fopen("student_info.txt", "wb");
	// output
	student_header();
	for(i = 0; i < n_student; i++)
	{
			printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st[i].id, st[i].name, st[i].gender, st[i].sclass,\
			st[i].year, st[i].address, st[i].phone);
			fwrite(&st[i], sizeof(student), 1, student_info);
	}
	printf("Sort and Write into file successfully...\n");
	fclose(student_info);
}
void del_student()
{
	FILE *student_info;
	FILE *tmp;
	student st;
	int idsearch, found = 0;
	
	student_info = fopen("student_info.txt", "rb");
	tmp = fopen("tmp_student.txt", "wb");
	
	printf("Enter student id to delete = ");scanf("%d", &idsearch);
	while(fread(&st, sizeof(student), 1, student_info))
	{
		if( idsearch == st.id)
		{
			printf("ID Found....\n");
			found = 1;
			delay(1);
			system("cls");
			student_header();
			printf("%04d  %-20s%-9s%-9s%-14d%-25s0%-15d\n", st.id, st.name, st.gender, st.sclass, st.year,\
			st.address, st.phone);
			printf("Data deleted....\n");
		}
		else
		{
			fwrite(&st, sizeof(student), 1, tmp);
		}
	}
	fclose(tmp);
	fclose(student_info);
	
	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	else{
		student_info = fopen("student_info.txt", "wb");
		tmp = fopen("tmp_student.txt", "rb");
		
		while(fread(&st, sizeof(student), 1, tmp))
		{
			fwrite(&st, sizeof(student), 1, student_info);
		}
		
		fclose(tmp);
		fclose(student_info);
	}
}
//###################################Student###################################### 

//###################################Score###################################### 
void input_score(){
	FILE *student_info;
	student st;
//	FILE *score_info;
//	score *sc;
//	sc = (score *)calloc(1,sizeof(score));
	 int bb=0; 
	 int id;
	 int sub;
	printf("Enter student_ID: ");
	scanf("%d",&id);
	student_info = fopen("student_info.txt", "rb");
//	score_info=fopen("score_info.txt","wb");

while(1==fread(&st,sizeof(struct Student_info),1,student_info)){
	if(id==st.id){
		printf("Student %s.\n\n",st.name);
	}
}
int i;
	FILE *score_info;
	score scc;
	//scc = (score *)calloc(1,sizeof(score));
	score_info=fopen("score_info.txt","ab");
	
//	for(i=0;i<sub;i++){
	printf("Enter score math: ");  scanf("%d" ,&scc.scm);
	printf("Enter score khmer: ");  scanf("%d" ,&scc.sck);
	printf("Enter score english: ");  scanf("%d" ,&scc.sce);
	scc.total=scc.sce+scc.sck+scc.scm;
	//printf("student name %s have %d scores.",st.name,scc.total);
	fwrite(&scc, sizeof(score), 1, score_info);
	printf("Data Record Successfully..\n");
//}
fclose(score_info); fclose(student_info); //remove("student_info.txt");
//rename("score.txt","student_info");
}
void output_score(){
	int id;
	FILE *score_info;
	score scc;
	//scc = (score *)calloc(1,sizeof(score));
	score_info=fopen("score_info.txt","rb");

	FILE *student_info;
	student st;
	student_info = fopen("student_info.txt", "rb");
	printf("Enter student_ID: ");
	scanf("%d",&id);
	score_header();
while(1==fread(&st,sizeof(struct Student_info),1,student_info)){
	if(id==st.id){
	while(fread(&scc,sizeof(struct Score),1,score_info)){
		printf("%-5s%-15d%-15d%-15d%-15d\n",st.name,scc.scm,scc.sck,scc.sce,scc.total);
		
	}
}
}
fclose(score_info);
fclose(student_info);
}
void update_score(){
	FILE *student_info;
	FILE *score_info;
	FILE *tmp;
	student st;
	score scc;
	int idsearch, found = 0;
	student_info=fopen("student_info.txt", "rb");
	score_info = fopen("score_info.txt", "rb");
	tmp = fopen("tmp.txt", "wb");
	printf("Enter subject id to update = ");scanf("%d", &idsearch);
	
	while(fread(&st,sizeof(struct Student_info),1,student_info)){
while(fread(&scc, sizeof(score), 1, score_info))
	{
		if( idsearch == st.id)
		{
			printf("hry\n");
			found = 1;
			//	while(1==fread(&scc, sizeof(struct Score), 1, score_info)){
			score_header();
			printf("%-15d%-15d%-15d%-15d\n",scc.scm,scc.sck,scc.sce,scc.total);
			printf("Enter new information:\n");
			printf("Enter New score math: ");  scanf("%d" ,&scc.scm);
			printf("Enter New score khmer: ");  scanf("%d" ,&scc.sck);
			printf("Enter NEW score english: ");  scanf("%d" ,&scc.sce);
			//break ;
		}
		fwrite(&scc, sizeof(score), 1, tmp);
	}
}


	if(!found)
	{
		printf("Subject ID not found..!!\n");
		printf("Make sure id is correct..\n");
	}
	//fclose(student_info);
	fclose(score_info);
	fclose(tmp);
	if(found)
	{   printf("hi\n");
		tmp = fopen("tmp.txt", "rb");
		score_info = fopen("score_info.txt", "wb");
		while(fread(&scc, sizeof(score), 1, tmp))
		{
			fwrite(&scc, sizeof(score), 1, score_info);
		}
		printf("Updated....\n");
		fclose(tmp);
		fclose(score_info);
	}
}
