/**
 * File CAdmin.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CAdmin".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#include "../include/CAdmin.h"

//Static Variable to assign Employee ID
int CAdmin::m_nEmpCount = 0;

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Header message for the program
// ------------------------------------------------------------------

void CAdmin::Intro( void )
{
    system( "cls" );
    cout<<"\t\t\tEmployee Management System\n\n\n";
}

// ------------------------------------------------------------------
// Method      : Hold
// Parameters  : Nil
// Returns     : Nil
// Description : Method to add a pause.
// ------------------------------------------------------------------
void CAdmin::Hold( void )
{
    cout<<"Press any key to continue.";
    getch();
}

// ------------------------------------------------------------------
// Method      : AddNew
// Parameters  : Nil
// Returns     : Nil
// Description : Method to add new user.
// ------------------------------------------------------------------
void CAdmin::AddNew( void )
{
    CFile file;

    Intro();
    cout<<"Registration"<<endl;
    cout<<string( 12,'_' );
    UserData();
    file.Write( m_employee );
    cout<<"Saving employee details."<<endl;
    sleep_for( seconds( 1 ) );
    system( "cls" );
    Intro();
    m_employee->View();
    cout<<endl;
    Hold();
    file.~CFile();
    delete m_employee;
}

// ------------------------------------------------------------------
// Method      : UserData
// Parameters  :
//  <param 1>  - <int nAdmNo> - Employee ID
// Returns     : Nil
// Description : Method that get employee data from user.
// ------------------------------------------------------------------
 void CAdmin::UserData( /*IN*/ int nEmpNo )
 {
    int nFlag = 0;
    char szName[MAX_LENGTH];
    int nAge;
    char cDesignation;
    int nContactNumber;
    char szEmail[MAX_LENGTH];

    cin.sync();
    cout<<"\nName\t\t\t\t: ";
    m_check.CharArray( szName, MAX_LENGTH, MAX_LENGTH - 1 );
    cout<<"Age\t\t\t\t: ";
    nAge = m_check.Integer( 18,80 );
    cout<<"Designations\n";
    cout<<"\t1. Manager"<<endl;
    cout<<"\t2. Project Leader"<<endl;
    cout<<"\t3. Trainee"<<endl;
    do
    {
        cout<<"\nEnter your designation\t\t: ";
        cDesignation = getche();
        cout<<endl;
        switch( cDesignation )
        {
            case '1': m_employee = new CManager;
                      nFlag = 1;
                      break;

            case '2': m_employee = new CProjectLeader;
                      nFlag = 1;
                      break;

            case '3': m_employee = new CTrainee;
                      nFlag = 1;
                      break;

            default : cout<<"Invalid input. Try again."<<endl;
                      nFlag = 0;
                      break;
        }
    }while( nFlag == 0);
    nFlag = 0;
    do
    {
        cout<<"Contact Number (6 digit)\t: ";
        nContactNumber = m_check.Integer();
        if( ( nContactNumber > 99999 ) && ( nContactNumber < 1000000 ) )
        {
            nFlag = 1;
        }
        else
        {
            nFlag = 0;
            cout<<"Error. Enter a valid 6 digit number\n";
        }
    }while( nFlag == 0 );
    cout<<"Email id\t\t\t: ";
    do
    {
       cin.getline( szEmail, MAX_LENGTH );
       nFlag = m_check.ValidateEmail( szEmail );
       if( nFlag == 0)
       {
           cout<<"Invalid Email. Try again."<<endl;
       }
       else
       {
           nFlag = 1;
       }
    } while( nFlag == 0);
    if( nEmpNo == 0 )
    {
         m_employee->AddNew( ++m_nEmpCount, szName, nAge, nContactNumber, szEmail );
    }
    else
    {
        m_employee->AddNew( nEmpNo, szName, nAge, nContactNumber, szEmail );
    }
 }

// ------------------------------------------------------------------
// Method      : GetSpec
// Parameters  : Nil
// Returns     : Nil
// Description : Method to retrieve a specific employee.
// ------------------------------------------------------------------
CEmployee CAdmin::GetSpec( void )
{
    CFile file;
    CEmployee data;
    char cChoice;
    char szName[MAX_LENGTH];

    Intro();
    cout<<"Search options"<<endl;
    cout<<string(14,'_')<<endl;
    cout<<"\n\t1. Name"<<endl;
    cout<<"\t2. Employee Id"<<endl;
    do
    {
        cout<<"Enter you choice : "<<endl;
        cChoice = getche();
        if(cChoice == '1')
        {
            Intro();
            cout<<"Name: ";
            m_check.CharArray( szName, MAX_LENGTH, MAX_LENGTH-1 );
            data = file.GetDataName( szName );
            if( data.GetEmployeeID() == -1 )
            {
                Hold();
                data = GetSpecAdm();
            }
            else
            {
                return data;
            }
        }
        else if( cChoice == '2' )
        {
            data = GetSpecAdm();
        }
        else
        {
            cout<<"Invalid Choice. Try again."<<endl;
        }
    }while( ( cChoice != '1' ) && ( cChoice != '2' ) );
    if( data.GetEmployeeID() == 0 )
    {
        cout<<"No record found.\n"<<endl;
        Hold();
    }
    return data;
}

// ------------------------------------------------------------------
// Method      : GetSpecADm
// Parameters  : Nil
// Returns     : Nil
// Description : Method to retrieve a specific employee with employee ID.
// ------------------------------------------------------------------
CEmployee CAdmin::GetSpecAdm( void )
{
    CFile file;
    int nAdmNo;
    CEmployee data;

    Intro();
    cout<<"Employee ID : ";
    nAdmNo = m_check.Integer();
    data = file.GetDataAdm( nAdmNo );
    return data;
}
// ------------------------------------------------------------------
// Method      : ViewSpec
// Parameters  : Nil
// Returns     : Nil
// Description : Method to details of a employee.
// ------------------------------------------------------------------
void CAdmin::ViewSpec( void )
{
    CEmployee data;

    data = GetSpec();
    if( data.GetEmployeeID() == -1 || data.GetEmployeeID() == 0 )
    {
        //unimplemented
    }
    else
    {
        data.View();
        Hold();
    }
}

 // ------------------------------------------------------------------
// Method      : ViewAll
// Parameters  : Nil
// Returns     : Nil
// Description : Method to view the entire database.
// ------------------------------------------------------------------
void CAdmin::ViewAll( void )
{
    CFile file;

    Intro();
    cout<<setw( 5 )<<setiosflags(ios::left)<<"ID";
    cout<<setw( 15 )<<setiosflags(ios::left)<<"Name";
    cout<<setw( 5 )<<setiosflags(ios::left)<<"AGE";
    cout<<setw( 8 )<<setiosflags(ios::left)<<"Salary";
    cout<<setw( 15 )<<setiosflags(ios::left)<<"Contact No.";
    cout<<setw( 15 )<<setiosflags(ios::left)<<"Post";
    cout<<setw( 18 )<<setiosflags(ios::left)<<" Avialable Leaves "<<endl;
    file.ViewAll();
    Hold();
    file.~CFile();
}

 // ------------------------------------------------------------------
// Method      : DeleteSpec
// Parameters  : Nil
// Returns     : Nil
// Description : Method to delete a specific employee.
// ------------------------------------------------------------------
void CAdmin::DeleteSpec( void )
{
    CFile file;
    CEmployee data;
    char cCheck;

    Intro();
    data = GetSpec();
    if( data.GetEmployeeID() == -1 || data.GetEmployeeID() == 0 )
    {
        //unimplemented
    }
    else
    {
        do
        {
        cout<<"Do you want to delete? (Y/N) :";
        cCheck = getche();
        cCheck = toupper(cCheck);
        cout<<endl;
        if( cCheck == 'Y' )
        {
            file.ClearSpec( data.GetEmployeeID() );
            cout<<"Record deleted."<<endl<<endl;
        }
        else if( cCheck == 'N' )
        {
            cout<<"Operation terminated."<<endl;
        }
        else
        {
            cout<<"Invalid input. Try again"<<endl;
        }
        }while( cCheck != 'Y' && cCheck != 'N' );
    }
    cin.sync();
    Hold();
}

// ------------------------------------------------------------------
// Method      : DeleteAll
// Parameters  : Nil
// Returns     : Nil
// Description : Method to clear the whole database.
// ------------------------------------------------------------------
void CAdmin::DeleteAll( void )
{
    CFile file;
    char cCheck;

    Intro();
    do
    {
        cin.sync();
        cout<<"Do you want to clear the file? (Y/N) :";
        cCheck = getche();
        cCheck = toupper(cCheck);
        cout<<endl;
        if( cCheck == 'Y' )
        {
            file.ClearFile();
            cout<<"File Cleared."<<endl<<endl;
        }
        else if( cCheck == 'N' )
        {
            cout<<"Operation terminated."<<endl;
        }
        else
        {
            cout<<"Invalid input. Try again"<<endl;
        }
    }while( cCheck != 'Y' && cCheck != 'N' );
    m_nEmpCount = 0;
    Hold();
    file.~CFile();
}

// ------------------------------------------------------------------
// Method      : Modify
// Parameters  : Nil
// Returns     : Nil
// Description : method to modify a record.
// ------------------------------------------------------------------
void CAdmin::Modify()
{
    CEmployee data;
    CFile file;

    data = GetSpec();
    if( data.GetEmployeeID() == -1 || data.GetEmployeeID() == 0 )
    {
        //unimplemented
    }
    else
    {
        m_employee = &data;
        UserData( data.GetEmployeeID() );
        file.ModifyFile( *m_employee );
        cout<<"Record Modified"<<endl;
        sleep_for( seconds( 1 ) );

    }
}

// ------------------------------------------------------------------
// Method      : LeaveApply
// Parameters  : Nil
// Returns     : Nil
// Description : method to apply for leave
// ------------------------------------------------------------------
void CAdmin::LeaveApply( void )
{
    CFile file;
    CEmployee data;
    int nLeave;

    Intro();
    data = GetSpec();
    if( data.GetEmployeeID() == -1 || data.GetEmployeeID() == 0 )
    {
        //unimplemented
    }
    else
    {
        cout<<"Number of days : ";
        nLeave = m_check.Integer();
        if( data.UpdateLeave( nLeave ) )
        {
            file.ModifyFile( data );
        }
        else
        {
            //unimplemented
        }
    }
    Hold();
}

// ------------------------------------------------------------------
// Method      : Menu
// Parameters  : Nil
// Returns     : Nil
// Description : Menu for the program
// ------------------------------------------------------------------
void CAdmin::Menu( void )
{
    Intro();
    cout<<"1. Add new"<<endl;
    cout<<"2. View Specific"<<endl;
    cout<<"3. View all"<<endl;
    cout<<"4. Delete specific"<<endl;
    cout<<"5. Delete all"<<endl;
    cout<<"6. Modify"<<endl;
    cout<<"7. Apply for leave"<<endl;
    cout<<"9. Exit"<<endl;
    HandleChoice();
}

// ------------------------------------------------------------------
// Method      : HandleChoice
// Parameters  : Nil
// Returns     : Nil
// Description : Function to handle the choice selected by user.
// ------------------------------------------------------------------
void CAdmin::HandleChoice( void )
{
    int nChoice;

    re:
    cout<<"\nEnter your choice (1-5 or 9): ";
    cin.sync();
    nChoice = m_check.Integer();
    switch( nChoice )
    {
    case 1:
        AddNew();
        break;

    case 2:
        ViewSpec();
        break;

    case 3:
        ViewAll();
        break;

    case 4:
        DeleteSpec();
        break;

    case 5:
        DeleteAll();
        break;

    case 6:
        Modify();
        break;

    case 7:
        LeaveApply();
        break;

    case 9:
        system( "cls" );
        cout<<"Program exiting\n\n";
        exit( 0 );
        break;

    default:
        cout<<"Invalid option.Try again.\n";
        goto re;
        break;
    }
}

// ------------------------------------------------------------------
// Method      : Manage
// Parameters  : Nil
// Returns     : Nil
// Description : The root method called from main.
// ------------------------------------------------------------------
void CAdmin::Manage( void )
{
    cout<<"\n\n\n\t\t   Welcome to Employee Management System";
    sleep_for( seconds( 2 ) );
    while( 1 )
    {
        system( "cls");
        Intro();
        Menu();
    }
}
// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Resets the m_nAdmCount each time the program is executed.
// ------------------------------------------------------------------
CAdmin::CAdmin( void )
{
    CFile file;

    m_nEmpCount = file.ReturnAdmnNo();
    file.~CFile();
}
