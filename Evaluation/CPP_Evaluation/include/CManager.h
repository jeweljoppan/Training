/**
 * File CManager.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CManager"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#ifndef CMANAGER_H
#define CMANAGER_H

#include "CEmployee.h"

#define BASICM 15000
#define ALLOWANCEM 0.6

/*
 * Class <CManager>
 * <A class which holds details of manager >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */

class CManager : public CEmployee
{
    public:
        void AddNew( int, char [], int, int, char [] );
        void Salary( void );
        CManager();
        virtual ~CManager();
};

#endif // CMANAGER_H
