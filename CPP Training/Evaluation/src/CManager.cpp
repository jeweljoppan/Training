/**
 * File CManager.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManager".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#include "../include/CManager.h"

// ------------------------------------------------------------------
// Method      : AddNew
// Parameters  :
//  <param 1>  - <int nAdmNo> - Employee number.
//  <param 2>  - <char szName[]> - Name of employee
//  <param 3>  - <int nContactNumber> - Contact number of employee,
//  <param 4>  - <char szEmail[]> - EmailId of employee.
// Returns     : Nil
// Description : Method that assigns the user data to data members.
// ------------------------------------------------------------------
void CManager::AddNew( /*IN*/ int nEmpNo,
                       /*IN*/ char szName[],
                       /*IN*/ int nAge,
                       /*IN*/ int nContactNumber,
                       /*IN*/ char szEmail[] )
{
    m_employee.nEmpNo = nEmpNo;
    strcpy( m_employee.szName, szName );
    m_employee.nAge = nAge;
    strcpy( m_employee.szDesignation, "Manager" );
    m_employee.nContactNumber = nContactNumber;
    strcpy( m_employee.szEmail, szEmail );
    m_employee.nLeave = 12;
    Salary();
}

// ------------------------------------------------------------------
// Method      : Salary
// Parameters  : Nil
// Returns     : Nil
// Description : Method that assigns the salary.
// ------------------------------------------------------------------
void CManager::Salary(void)
{
    m_employee.fSalary = BASICM + BASICM * ALLOWANCEM;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Allocates memory to object.
// ------------------------------------------------------------------
CManager::CManager()
{
    //ctor
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates memory.
// ------------------------------------------------------------------
CManager::~CManager()
{
    //dtor
}
