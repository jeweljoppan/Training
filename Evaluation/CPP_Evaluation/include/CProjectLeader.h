/**
 * File CProjecLeader.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CProjectLeader"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#ifndef CPROJECTLEADER_H
#define CPROJECTLEADER_H

#include "CEmployee.h"

#define BASICP 10000
#define ALLOWANCEP 0.4

/*
 * Class <CProjectLeader>
 * <A class which holds details of project leader. >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */

class CProjectLeader : public CEmployee
{
    public:
        void AddNew( int, char [], int, int, char [] );
        CProjectLeader();
        void Salary( void );

        virtual ~CProjectLeader();
};

#endif // CPROJECTLEADER_H
