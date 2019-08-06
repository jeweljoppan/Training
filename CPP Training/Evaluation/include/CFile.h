/**
 * File CFile.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CFile" to handle files.
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */

#ifndef CFILE_H
#define CFILE_H

#include <fstream>
#include "CEmployee.h"

/*
 * Class <CFile>
 * <A class which handles all the file operations. >
 * Author : Jewel Jo Prince
 * Version : 1.0.0
 * Date : 26-07-2019
 *
 */


class CFile
{
    private:
        fstream storage;
    public:
        CFile( void );
        void Write( CEmployee * );
        CEmployee GetDataAdm( int nEmpNo = 0 );
        CEmployee GetDataName( char * );
        int ReturnAdmnNo( void );
        void ViewAll( void );
        void ModifyFile( CEmployee );
        void ClearSpec( int );
        void ClearFile( void );
        ~CFile( void );
};

#endif // CFILE_H
