/**
 * File CAdmin.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CAdmin"
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#ifndef CADMIN_H
#define CADMIN_H

#include <chrono>
#include <thread>
#include "CFile.h"
#include "CInputValidate.h"
#include "CManager.h"
#include "CProjectLeader.h"
#include "CTrainee.h"

using namespace std::this_thread;
using namespace std::chrono;

/*
 * Class <CAdmin>
 * <A class which manages the control flow of program.>
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */

class CAdmin
{
    private:
        CEmployee *m_employee;
        CInputValidate m_check;
        void Intro( void );
        void Hold( void );
        void AddNew( void );
        void UserData( int EmpNo = 0 );
        CEmployee GetSpec( void );
        CEmployee GetSpecAdm( void );
        void ViewSpec( void );
        void ViewAll( void );
        void DeleteSpec( void );
        void DeleteAll( void );
        void Modify( void );
        void LeaveApply( void );
        void Menu( void );
        void HandleChoice( void );
    public:
        CAdmin( void );
        void Manage( void );
        static int m_nEmpCount;

};

#endif // CADMIN_H
