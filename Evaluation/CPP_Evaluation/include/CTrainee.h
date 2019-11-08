/**
 * File CTrainee.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CTrainee"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

 #ifndef CTRAINEE_H
#define CTRAINEE_H

#include "CEmployee.h"

#define BASICT 4000
#define ALLOWANCET 0.1

/*
 * Class <CTrainee>
 * <A class which holds details of Trainee. >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */


class CTrainee : public CEmployee
{
    public:
        void AddNew( int, char [], int, int, char [] );
        void Salary();
        CTrainee();
        virtual ~CTrainee();

};

#endif // CTRAINEE_H
