/*
 * main.h
 *
 *  Created on: Mar 21, 2024
 *      Author: Maciej Wasiluk
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct {
	int enrollNumber; // has to be != 0 for active student
	char name[30];
	char major[50];
	char dob[15];
	int semester;
} STUDENT_t;

void display_students(STUDENT_t *students_records, uint8_t *records_size);
int search_for_any_record(STUDENT_t *students_records, uint8_t *records_size);
void add_student(STUDENT_t *students_record, uint8_t *record_size);
int check_if_record_exist(STUDENT_t *students_records, uint8_t *records_size, int *enrollNumber);
int search_for_free_record(STUDENT_t *students_records, uint8_t *records_size);
void delete_student(STUDENT_t *students_records, uint8_t *records_size);

#endif /* MAIN_H_ */
