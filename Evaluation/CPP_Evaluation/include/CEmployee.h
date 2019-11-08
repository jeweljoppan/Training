/**
 * File Cemployee.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CEmployee"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H


#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

#define MAX_LENGTH 20
#define DATE_MAX_LENGTH 11
#define ADM_MAX_LENGTH 5
#define LEAVE_MAX_LENGTH

using namespace std;

//A structure that holds all data of the employees.
struct stEmployee
{
    int nEmpNo;
    char szName[MAX_LENGTH];
    int nAge;
    float fSalary;
    char szDesignation[MAX_LENGTH];
    int nContactNumber;
    char szEmail[MAX_LENGTH];
    int nLeave;
};

/*
 * Class <CEmployee>
 * <A class which is the base of CManager, CProjectLeader, CTrainee. >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */

class CEmployee
{
    protected:
        struct stEmployee m_employee;
    public:
        virtual void AddNew( int, char [], int, int, char [] );
        int GetEmployeeID( void );
        int UpdateLeave( int );
        char* GetEmpName( void );
        void ShowLeave( void );
        void View( void );
        void ViewTab( void );
        virtual void Salary( void );
        CEmployee( void );
        virtual ~CEmployee( void );
};

#endif // CEMPLOYEE_H
