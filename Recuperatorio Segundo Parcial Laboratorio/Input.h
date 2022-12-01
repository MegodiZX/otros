/*
 * Input.h
 *
 *  Created on: 12 nov. 2022
 *      Author: 54112
 */

#ifndef INPUT_H_
#define INPUT_H_

int getInt(char* message);
void getFloat(char* message, float* number);
void getChar(char* message, char* letter);
void getString(char* message, char* myString);
int getStringJustLetters(char* message, char* input);
void getSex(char* input);
int getStringNumbers(char* message, char* input);
int getStringFloatNumber(char* message, char* input);
void getValidFloat(float* finalFloat, char* message, float lowLimit, float hiLimit);
void getValidString (char* message, char* input, int ssize);
void getValidInt(int* finalInt, char* message, int lowLimit, int hiLimit);
void getValidSex(char* letter);
int verifyConformity (char* message, char* cancelMessage);

#endif /* INPUT_H_ */
