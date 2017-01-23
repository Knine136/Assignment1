/* CS261 - Assignment 1 - Q.1*/
/* Name: Kristine Catimbang
 * Date: 1/23/2017
 * Solution Description: This program generates an array of 10 students, assigns randomly generated scores to each one, prints the outcomes,
 * sorts the scores, prints the average score, and frees memory when the program is done running.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
	struct student* stud = (struct student*)malloc(10*sizeof(struct student));
	return stud;
}

void generate(struct student* students){
	for(int i = 0; i < 10; i++){
		students[i].id = i;
		int id = students[i].id;
		students[i].score = (10 * id) % 50;
	}
} 

void output(struct student* students){
	for(int i = 0; i < 10; i++){
		printf("ID%d Score%d\n", students[i].id, students[i].score);
	}
}

int min(struct student* students){
	int min;
	min = 100;

	for(int i = 0; i < 10; i++){
		if(students[i].score < min){
			min = students[i].score;
		}
	}

	return min;
}

float avg(struct student* students){
	int total;
	float average;
	for(int i = 0; i < 10; i++){
		total += students[i].score;
		average = total/10;
	}
	return average;
}

void sort(struct student* students){
	int temp;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(students[i].score > students[j].score){
				temp = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp;
			}
		}
	}
}

void deallocate(struct student* students){
	if(students != NULL){
		free(students);
		students = 0;
	}
}

int main(){
	struct student* stud = allocate();
	generate(stud);
	output(stud);
	sort(stud);
	
	for(int i = 0; i < 10; i++){
		printf("%d %d\n", stud[i].id, stud[i].score);
	}

	printf("Avg: %f \n", avg(stud));
	printf("Min: %d \n", min(stud));

	return 0;
}
