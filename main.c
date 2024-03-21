/*
 * main.c
 *
 *  Created on: Mar 21, 2024
 *      Author: Maciej Wasiluk
 */

#include <stdio.h>
#include <stdint.h>
#include "main.h"

int main() {

		uint8_t records_size = 10;
		STUDENT_t students_records[records_size];
		for(int i = 0; i < records_size; i++) {
			students_records[i].enrollNumber = 0;
		}

		int user_input = 4;

	for(;;) {

		printf("Students' record management program\n");
		printf("Display all records -->1\n");
		printf("Add new record      -->2\n");
		printf("Delete a record     -->3\n");
		printf("Exit application    -->0\n");
		printf("Enter your option here:");

		while((scanf("%d", &user_input) <= 0) ||
		     (user_input < 0) ||
			 (user_input > 3)) {
			fflush(stdin);
			fflush(stdin);
			printf("Please enter '1', '2', '3' or '0':");
		}

		switch(user_input) {

		case 1:
			display_students(students_records, &records_size);
			break;
		case 2:
			add_student(students_records, &records_size);
			break;
		case 3:
			delete_student(students_records, &records_size);
			break;
		case 0:
			return 0;
		}
	}

	return 0;
}

void display_students(STUDENT_t *students_records, uint8_t *records_size) {

	if(!search_for_any_record(students_records, records_size)) {
		printf("Currently there is no record in system\n");
		return;
	}

	printf("Displaying all students records:\n");

	for(int i = 0; i <= (*records_size -1); i++) {

		if(students_records[i].enrollNumber == 0)
			continue;

		printf("**********\n");
		printf("enrollNumber       : %d\n", students_records[i].enrollNumber);
		printf("studetnSemester    : %d\n", students_records[i].semester);
		printf("studentDateOfBirth : %s\n", students_records[i].dob);
		printf("studentMajor       : %s\n", students_records[i].major);
		printf("studentName        : %s\n", students_records[i].name);

	}

	printf("**********\n");
}

int search_for_any_record(STUDENT_t *students_records, uint8_t *records_size) {

	for(int i = 0; i <= (*records_size -1); i++) {
		if(students_records[i].enrollNumber != 0)
			return 1;
	}

	return 0;

}

void add_student(STUDENT_t *students_records, uint8_t *records_size) {

	if(!search_for_free_record(students_records, records_size)) {
		printf("You cannot add more students' records\n");
		return;
	}

	uint8_t record_num = 0;

	for(int i = 0; i <= (*records_size -1); i++) {
		if(students_records[i].enrollNumber == 0) {
			record_num = i;
			break;
		}
	}

	int enrollNumber = 0;

	printf("Enter the enrollNumber: ");
	scanf("%d", &enrollNumber);
	while(check_if_record_exist(students_records, records_size, &enrollNumber)) {
		printf("There already exist record with that enrollNumber\n");
		printf("Enter the enrollNumber: ");
		scanf("%d", &enrollNumber);
	}
	students_records[record_num].enrollNumber = enrollNumber;
	printf("Enter the studentSemester: ");
	scanf("%d", &students_records[record_num].semester);
	printf("Enter the studentDateOfBirth (dd/mm/yyyy): ");
	scanf("%s", students_records[record_num].dob);
	printf("Enter the studentMajor: ");
	fflush(stdin);
	scanf("%[^\n]s", students_records[record_num].major);
	printf("Enter the studentName: ");
	fflush(stdin);
	scanf("%[^\n]s", students_records[record_num].name);

}

int check_if_record_exist(STUDENT_t *students_records, uint8_t *records_size, int *enrollNumber) {

	for(int i = 0; i < (*records_size -1); i++) {
		if(students_records[i].enrollNumber == *enrollNumber)
			return 1;
	}

	return 0;
}

int search_for_free_record(STUDENT_t *students_records, uint8_t *records_size) {

	for(int i = 0; i <= (*records_size -1); i++) {
		if(students_records[i].enrollNumber == 0)
			return 1;
	}

	return 0;

}

void delete_student(STUDENT_t *students_records, uint8_t *records_size) {

	if(students_records->enrollNumber == 0) {
		printf("Currently there is no record in system\n");
		return;
	}

	int enroll_number = 0;

	printf("Enter the enrollNumber of the student: ");

	while((scanf("%d", &enroll_number) <= 0) ||
			     (enroll_number <= 0)) {
		fflush(stdin);
		fflush(stdin);
		printf("Enroll number has to be positive integral");
	}

	for(int i = 0; i < (*records_size -1); i++) {
		if(students_records[i].enrollNumber == enroll_number) {
			students_records[i].enrollNumber = 0;
			students_records[i].semester = 0;
			students_records[i].dob[0] = '\0';
			students_records[i].major[0] = '\0';
			students_records[i].name[0] = '\0';
			printf("Record deleted\n");
			return;
		}
	}

	printf("There is no record with given enrollNumber\n");
}
