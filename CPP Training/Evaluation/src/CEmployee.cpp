/**
 * File CEmployee.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CEmployee".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#include "../include/CEmployee.h"

// ------------------------------------------------------------------
// Method      : ViewTab
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the user details in tabular format.
// ------------------------------------------------------------------
void CEmployee::ViewTab( void )
{
    cout<<setw( 5 )<<setiosflags(ios::left)<<m_employee.nEmpNo;
    cout<<setw( 15 )<<setiosflags(ios::left)<<m_employee.szName;
    cout<<setw( 5 )<<setiosflags(ios::left)<<m_employee.nAge;
    cout<<setw( 8 )<<setiosflags(ios::left)<<m_employee.fSalary;
    cout<<setw( 15 )<<setiosflags(ios::left)<<m_employee.nContactNumber;
    cout<<setw( 15 )<<setiosflags(ios::left)<<m_employee.szDesignation;
    cout<<setw( 18 )<<setiosflags(ios::left)<<m_employee.nLeave<<endl;
}

// ------------------------------------------------------------------
// Method      : View
// Parameters  : Nil
// Returns     : Nil
// Description : Prints the employee details.
// ------------------------------------------------------------------
void CEmployee::View( void )
{
    cout<<"ID\t\t\t: "<<m_employee.nEmpNo<<endl;
    cout<<"Name\t\t\t: "<<m_employee.szName<<endl;
    cout<<"AGE\t\t\t: "<<m_employee.nAge<<endl;
    cout<<"Salary\t\t\t: "<<m_employee.fSalary<<endl;
    cout<<"Contact No.\t\t: "<<m_employee.nContactNumber<<endl;
    cout<<"Post\t\t\t: "<<m_employee.szDesignation<<endl;
    cout<<"Available Leaves\t: "<<m_employee.nLeave<<endl<<endl;
}

// ------------------------------------------------------------------
// Method      : AddNew
// Parameters  :
//  <param 1>  - <int nAdmNo> - Employee number.
//  <param 2>  - <char szName[]> - Name of employee
//  <param 3>  - <int nContactNumber> - Contact number of employee,
//  <param 4>  - <char szEmail[]> - EmailId of employee.
// Returns     : Nil
// Description : Virtual Method that assigns the user data to data members.
// ------------------------------------------------------------------
void CEmployee::AddNew( /*IN*/ int nEmpNo,
                       /*IN*/ char szName[],
                       /*IN*/ int nAge,
                       /*IN*/ int nContactNumber,
                       /*IN*/ char szEmail[] )
{
    m_employee.nEmpNo = nEmpNo;
    strcpy( m_employee.szName, szName );
    m_employee.nAge = nAge;
    strcpy( m_employee.szDesignation, "_" );
    m_employee.nContactNumber = nContactNumber;
    strcpy( m_employee.szEmail, szEmail );
    m_employee.nLeave = 0;
    m_employee.fSalary = 0;
}

// ------------------------------------------------------------------
// Method      : GetAdmNo
// Parameters  : Nil
// Returns     : int
// Description : Returns the employee ID.
// ------------------------------------------------------------------
int CEmployee::GetEmployeeID( void )
{
    return m_employee.nEmpNo;
}

// ------------------------------------------------------------------
// Method      : GetEmpName
// Parameters  : Nil
// Returns     : int
// Description : Returns the employee name.
// ------------------------------------------------------------------
char* CEmployee::GetEmpName( void )
{
    return m_employee.szName;
}

int CEmployee::UpdateLeave( /*IN*/ int nLeave )
{
    if( nLeave > m_employee.nLeave )
    {
        cout<<"\nLeave limit exceeded."<<endl;
        cout<<"Available leave(s) : "<<m_employee.nLeave;
        return 0;
    }
    else
    {
        cout<<"\nLeave Approved."<<endl;
        m_employee.nLeave = m_employee.nLeave - nLeave;
        cout<<"Available leave(s) : "<<m_employee.nLeave<<endl;
        return 1;
    }
}

// ------------------------------------------------------------------
// Method      : Salary
// Parameters  : Nil
// Returns     : int
// Description : Virtual method to find the salary of the employee.
// ------------------------------------------------------------------
void CEmployee::Salary( void )
{
    m_employee.fSalary = 0;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : int
// Description : Allocates the object memory.
// ------------------------------------------------------------------
CEmployee::CEmployee( void )
{
    //ctor
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : int
// Description : Deallocates the object memory.
// ------------------------------------------------------------------
CEmployee::~CEmployee( void )
{
    //dtor
}
