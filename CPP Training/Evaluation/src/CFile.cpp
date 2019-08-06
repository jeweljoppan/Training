/**
 * File CFile.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the definitions of a Class "CFile" to handle files.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 26-07-2019
 *
 */

#include "../include/CFile.h"

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Opens the file to storage.
// ------------------------------------------------------------------
CFile::CFile( void )
{
    storage.open( "Employee.dat",ios::in | ios::out| ios::binary );
    if( !storage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {

    }
}

// ------------------------------------------------------------------
// Method      : Write
// Parameters  :
//  <param 1>  - <CEmployee data> - Employee object that has
//                                 to be written to file.
// Returns     : Nil
// Description : The method to write object to file.
// ------------------------------------------------------------------
void CFile::Write( /*IN*/ CEmployee *data )
{
    storage.seekp( 0L, ios::end );
    storage.write( ( char* )&( *data ), sizeof ( *data ) );
    storage.flush();
}

// ------------------------------------------------------------------
// Method      : GetDataAdm
// Parameters  :
// <param 1>   - <int nAdmNo> - Admission number of the student that
//                              has to be searched
// Returns     : CStudent
// Description : Searches the file to find the object matching to the
//               admission number.
// ------------------------------------------------------------------
CEmployee CFile::GetDataAdm( /*IN*/ int nEmpNo )
{
    CEmployee temp;
    int nFlag = 0;

    storage.seekg( 0, ios::beg );
    while( storage.read( ( char* )&temp,sizeof( temp ) ) )
    {
        if( nEmpNo == temp.GetEmployeeID() )
        {
            return temp;
        }
        else
        {
            //Unimplemented
        }
    }
    temp.AddNew( 0, "_", 0, 0 , "_" );
    return temp;
}

// ------------------------------------------------------------------
// Method      : GetDataName
// Parameters  :
// <param 1>   - <char *pszName> - Name of the student that
//                              has to be searched
// Returns     : CStudent
// Description : Searches the file to find the object matching to the
//               admission number.
// ------------------------------------------------------------------
CEmployee CFile::GetDataName( /*IN*/ char *pszName )
{
    CEmployee temp1, temp2;
    int nFlag = 0;

    while( storage.read( ( char* )&temp1,sizeof( temp1 ) ) )
    {
        if( strcmp( pszName, temp1.GetEmpName() ) == 0 )
        {
            temp2 = temp1;
            ++nFlag;
        }
        else
        {
            temp1.AddNew( 0, "_", 0, 0 , "_" );
        }
    }
    if( nFlag == 1 )
    {
        return temp2;
    }
    else if( nFlag == 0)
    {
        cout<<"No Record found."<<endl<<endl;
        temp1.AddNew( 0, "_", 0, 0 , "_" );
    }
    else
    {
        cout<<"More than 1 result found. Enter additional data."<<endl<<endl;
        temp1.AddNew( -1, "_", 0, 0 , "_" );
    }
    return temp1;
}


// ------------------------------------------------------------------
// Method      : ReturnAdmnNo
// Parameters  : Nil
// Returns     : int
// Description : Method that returns the admission number of recently
//               added student.
// ------------------------------------------------------------------
int CFile::ReturnAdmnNo( void )
{
    CEmployee data;
    int nTemp = sizeof( data ) * -1;

    storage.seekg( nTemp, ios::end );
    storage.read( ( char* )( &data ), sizeof( data ) );
    return data.GetEmployeeID();
}

// ------------------------------------------------------------------
// Method      : ViewAll
// Parameters  : Nil
// Returns     : Nil
// Description : Methods to print all records in the file.
// ------------------------------------------------------------------
void CFile::ViewAll( void )
{
    CEmployee temp;
    int nFlag = 0;

    storage.seekp( 0L, ios::beg );
    storage.seekg( 0L, ios::beg );
    while( storage.read( ( char* )&temp, sizeof( CEmployee ) ) )
    {
        temp.ViewTab();
        cout<<endl;
        nFlag = 1;
    }
    if( nFlag == 0 )
    {
        system( "cls" );
        cout<<"\n\n\t\tFile Empty\n\n"<<endl;
    }
    else
    {
        //unimplemented
    }
}

// ------------------------------------------------------------------
// Method      : ModifyFile
// Parameters  :
//  <param 1>  - <CStudent data> - The modified record.
// Returns     : Nil
// Description : The function to modify the details of a particular student.
// ------------------------------------------------------------------
void CFile::ModifyFile( /*IN*/ CEmployee data )
{
    CEmployee temp;
    int nSize = sizeof( temp ) * -1;
    temp = GetDataAdm( data.GetEmployeeID() );
    if( temp.GetEmployeeID() == 0)
    {
        cout<<"No data found."<<endl;
    }
    else
    {
        storage.seekg( nSize, ios::cur );
        storage.write( ( char* )( &data ), sizeof( data ) );
        storage.flush();
    }
}
// ------------------------------------------------------------------
// Method      : ClearSpec
// Parameters  :
//  <param 1>  - <int nAdmNo> - Admission number of student record that has
//                              to be deleted.
// Returns     : Nil
// Description : Function to clear a specific student record.
// ------------------------------------------------------------------
void CFile::ClearSpec( /*IN*/ int nEmpNo )
{
    CEmployee temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( storage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetEmployeeID() != nEmpNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }
    fout.close();
    storage.close();
    remove( "Employee.dat" );
    rename( "temp.dat", "Employee.dat" );
}
// ------------------------------------------------------------------
// Method      : ClearFile
// Parameters  : Nil
// Returns     : Nil
// Description : Method to clear the file.
// ------------------------------------------------------------------
void CFile::ClearFile( void )
{
    storage.close();
    remove( "Employee.dat" );
    storage.open("Employee.dat", ios::out | ios::binary );
    if( !storage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : TO clear the class object from memory
// ------------------------------------------------------------------
CFile::~CFile( void )
{
    storage.close();
}
