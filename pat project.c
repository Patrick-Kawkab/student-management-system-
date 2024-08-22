/*
 * project.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Patrick Kawkab
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student {
	int id;
	char name[100];
	int age;
	float gpa;
};//struct for students
struct student *sptr;//pointer to struct for student struct
struct node{
	struct student data;
	struct node *next;
};//struct for linked list
struct node *HEAD=NULL;//pointer to struct for head
int s_counter=0;//counter to count number of students
void addstruct(struct student s);//function to add students
void disp(struct node *ptr);// function to display students
int foruser(int *choice);//function that takes input from user
void search(void);//function that takes id and searches for it
void delete(void);//function that deletes struct node
void update(void);//function that takes id and updates it
void HIGHIEST(void);//function that search for the highest GPA
void avg_gpa(void);//function that calculates gpa avg
int foruser(int* choice){
	printf("1.Add Students\n");
	printf("2.Display Students\n");
	printf("3.Search Student by ID\n");
	printf("4.Update Student information\n");
	printf("5.Delete Student\n");
	printf("6.Calculate Average GPA\n");
	printf("7.Search for Student with Highest GPA\n");
	printf("8.Exit\n");
	printf("Enter Your Choice:");
	scanf("%d",&*choice);// passing value by reference
	if (*choice==1){//if statement to check user choice and access function required
		struct student s[s_counter];
		addstruct(s[s_counter]);
	}
	else if (*choice==2){
		if(HEAD==NULL){//to check if there is no input in linked list yet
			printf("-----------------------------------------------------\n");
			printf("No Students to Display\n");
			printf("-----------------------------------------------------\n");
			return 0;
		}
		printf("-----------------------------------------------------\n");
		 struct node *ptr=HEAD;//makes new pointer for checking on the linked list and not change head position
		disp(ptr);
		printf("-----------------------------------------------------\n");
	}
	else if (*choice==3){
		search();
	}
	else if (*choice==4){
		update();
	}
	else if (*choice==5){
		delete();
	}
	else if (*choice==6){
		avg_gpa();
	}
	else if (*choice==7){
		HIGHIEST();
	}
	else if (*choice==8){
		printf("-----------------------------------------------------\n");
		printf("Exiting...\n");
		printf("-----------------------------------------------------\n");
		return *choice;
	}
	else{//any other number is an invalid choice
		printf("-----------------------------------------------------\n");
		printf("invalid try again\n");
		printf("-----------------------------------------------------\n");
	}
	return 0;
}
void addstruct(struct student s){
	int ID;
	char name[100];
	int age;
	float gpa;
	struct node *temp=HEAD;//to not change where the head is pointing
	printf("-----------------------------------------------------\n");
	printf("Enter Student ID:");
	scanf("%d",&ID);//storing input in variables to check if the id is already reserved
	printf("Enter Student Name:");
	 scanf("\n");//handles an error because the next function handles new line
	gets(name);//this function handles spaces in the string an waits for user to press enter
	printf("Enter Student Age:");
	scanf("%d",&age);
	printf("Enter Student GPA:");
	scanf("%f",&gpa);
	printf("-----------------------------------------------------\n");
	while(temp!=NULL){//loops till linked list till null
		if(ID==temp->data.id){
			printf("This ID is already Reserved\n");//if statement to check if the input id is already reserved
			printf("-----------------------------------------------------\n");
			return;
		}
		temp=temp->next;//checks to next place in linked list
	}
	s.age=age;// points these variables in struct data
	strncpy(s.name,name,sizeof(s.name));//strncpy copies string to another string
	s.id=ID;
	s.gpa=gpa;
	struct node *new=(struct node*)malloc(sizeof(struct node));//adding struct
	new->data=s;//saves data in struct linked list
	new->next= HEAD;//points struct new to where head is pointing
	HEAD=new;//points head to new place
	s_counter++;//one student is added
	return;
}
void disp(struct node *ptr){
	if(ptr==NULL){
		return;
	}
	disp(ptr->next);
	printf("[ID:%d,Name:%s,Age:%d,GPA:%.2f]\n",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.gpa);//displays student
}
void search(void){
	if(HEAD==NULL){
		printf("-----------------------------------------------------\n");
		printf("No Students to Search\n");
		printf("-----------------------------------------------------\n");
	 return;
	}
	struct node *temp=HEAD;
	int ID;
	printf("-----------------------------------------------------\n");
	printf("Enter ID to Search:");
	scanf("%d",&ID);// takes id to search for
	printf("-----------------------------------------------------\n");
	while(temp!=NULL){
		if(ID==temp->data.id){//checking student with specific ID
			printf("[ID:%d,Name:%s,Age:%d,GPA:%.2f]\n",temp->data.id,temp->data.name,temp->data.age,temp->data.gpa);
			printf("-----------------------------------------------------\n");
			return;
		}
		temp=temp->next;
	}
	printf("student with ID %d is Not Found\n",ID);// if it ends looping without returning then this id isn't found
	printf("-----------------------------------------------------\n");

}
void update(void){
	if(HEAD==NULL){
		printf("-----------------------------------------------------\n");
		printf("No Students to Update\n");
		printf("-----------------------------------------------------\n");
		return;
	}
	int ID;
	struct node* ptr=HEAD;
	printf("-----------------------------------------------------\n");
	printf("Enter ID to Update:");
	scanf("%d",&ID);// takes id to update
	while(ptr!=NULL){// loops till the end of linked list
		if(ID==ptr->data.id){//checking student with specific ID
			printf("Enter new name:");
			scanf("\n");
			gets(ptr->data.name);
			printf("Enter new age:");
			scanf("%d",&ptr->data.age);
			printf("Enter new GPA:");
			scanf("%f",&ptr->data.gpa);
			printf("-----------------------------------------------------\n");
			return;
		}
		ptr=ptr->next;
	}
	printf("Student with ID %d is not found\n",ID);// if it ends looping without returning then this id isn't found
	printf("-----------------------------------------------------\n");


}
void delete(void){
	if(HEAD==NULL){
		printf("-----------------------------------------------------\n");
		printf("No Students to Delete\n");
		printf("-----------------------------------------------------\n");
		return;
	}
	struct node *prev=NULL;
	struct node *delete_node=NULL;
	struct node *current=NULL;
	int ID;
	printf("-----------------------------------------------------\n");
	printf("Enter ID to Delete its Data:");
	scanf("%d",&ID);
	printf("-----------------------------------------------------\n");
	if(HEAD->data.id==ID){//checks if the where head is pointing is data needed to delete
		delete_node=HEAD;
		HEAD=HEAD->next;
		free(delete_node);
		printf("Student with %d ID is Deleted\n",ID);
		printf("-----------------------------------------------------\n");
		s_counter--;
		return;
	}
	prev=HEAD;
	current=HEAD->next;
	while(current!=NULL){//checks all the linked list for the id to delete

		if(ID==current->data.id){
			delete_node=current;
			prev->next=current->next;
			free(delete_node);
			printf("Student with ID %d is Deleted:\n",ID);
			printf("-----------------------------------------------------\n");
			s_counter--;
			return;
		}
		prev=current;
		current=current->next;
	}
	printf("Student with ID %d is Not Found\n",ID);// if could has not returned yet then id not found
	printf("-----------------------------------------------------\n");
	return;

}
void avg_gpa(void){
	if(HEAD==NULL){
		printf("-----------------------------------------------------\n");
		printf("No Students to Count Average GPA\n");
		printf("-----------------------------------------------------\n");
		return;
	}
	struct node *temp=HEAD;
	float sum=0;
	float avg=0;
	while(temp!=NULL){// sums all the students gpa
		sum+=temp->data.gpa;
		temp=temp->next;
	}
	printf("-----------------------------------------------------\n");
	avg=sum/(float)s_counter;//the casting is because s_counter is an integer
	printf("GPA average=%.2f\n",avg);
	printf("-----------------------------------------------------\n");
}
void HIGHIEST(void){
	if(HEAD==NULL){
		printf("-----------------------------------------------------\n");
		printf("No Students to Check Highest GPA on\n");
		printf("-----------------------------------------------------\n");
		return;
	}
	struct node *temp=HEAD;
	struct node *big=temp;
	while (temp!=NULL){
		if(temp->data.gpa>=big->data.gpa){//checks if there is any GPA higher than big
			big=temp;
		}

		temp=temp->next;
	}
	printf("-----------------------------------------------------\n");
	printf("student with the highest GPA:\n");
	printf("[ID:%d,Name:%s,Age:%d,GPA:%.2f]\n",big->data.id,big->data.name,big->data.age,big->data.gpa);
	printf("-----------------------------------------------------\n");
	return;
}
int main(void){
	int choice=0;
	do {
		foruser(&choice);//calls function that takes input from user
	} while (choice != 8);//8 is the only exit number
	return 0;
}

